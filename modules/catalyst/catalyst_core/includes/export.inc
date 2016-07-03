<?php

/**
 * @file
 * Commom export related functions for catalyst.
 */

/**
 * Get all catalyst export groups.
 */
function catalyst_get_export_groups() {
  $groups = &drupal_static(__FUNCTION__);
  if (!isset($groups)) {
    $groups = array();
    $plugins = catalyst_get_plugin_info();
    $implements_prepare = module_implements('catalyst_prepare_export');
    foreach ($plugins AS $type => $group) {
      if ($group['exportables']) {
        $group += array(
          'type' => $type,
          'export callback' => 'catalyst_json_encode_exports',
          'export type' => 'json',
          'export options' => array(),
          'migration sources' => array(),
          'weight' => isset($group['migration sources']) ? count($group['migration sources'])*-1 : 0,
          'requires prepare' => in_array($group['module'], $implements_prepare),
        );
        if (!isset($group['export filename'])) {
          $group['export filename'] = $type . '.' . $group['export type'];
        }
        // Set the prepare callback by default allowing groups to override it
        if ($group['requires prepare'] && !isset($group['prepare callback'])) {
          $group['prepare callback'] = $group['module'] . '_catalyst_prepare_export';
        }
        $groups[$type] = $group;
      }
    }
    uasort($groups, 'drupal_sort_weight');
  }
  return $groups;
}

/**
 * Build all export data.
 */
function catalyst_build_export_data($exports, $groups, $name = 'Catalyst') {
  $exports = catalyst_expand_exports($exports, $groups);
  return array(
    'exports' => catalyst_prepare_exports($exports, $groups),
    'info' => catalyst_prepare_exports_info($name, $exports, $groups),
  );
}


/**
 * Expand exports attaching dependencies and files.
 */
function catalyst_expand_exports($exports, $groups) {
  // Build the collection of exports based on form input and export dependencies
  foreach (array_keys($exports) AS $type) {
    $group = $groups[$type];
    // Collect the export ids from submitted values
    foreach ($exports[$type] AS $id => &$export) {
      // Add dependency exports for this item
      $exports = catalyst_merge_exports($exports,
        catalyst_expand_export($export, $groups[$type], $groups));
    }
  }
  return $exports;
}

/**
 * Prepare exports for finally being exported.
 *
 * Exports may originate as an entity but are exported as a normalized object
 * depending on the group's prepare callback.
 */
function catalyst_prepare_exports($unprepared_exports, $groups) {
  $exports = array();
  // Process attached files
  if (isset($unprepared_exports['attached_files'])) {
    $attached_files = $unprepared_exports['attached_files'];
    $exports['attached_files'] = catalyst_prepare_export_files($attached_files);
    unset($unprepared_exports['attached_files']);
  }
  // Process the exports by group
  foreach ($unprepared_exports AS $type => $group_exports) {
    $group = $groups[$type];
    foreach ($group_exports AS $id => $export) {
      // Prepare export items individually if the group requires it
      // This allows an entity to be normalized before export/import
      if ($group['requires prepare']) {
        $prepare_callback = $group['prepare callback'];
        // Todo: Ensure function exists, die if it doesn't
        $group_exports[$id] = call_user_func($prepare_callback, $export, $group, $unprepared_exports);
        // Allow modules to alter each export
      }
      drupal_alter('catalyst_export', $group_exports[$id], $export, $group, $unprepared_exports);
    }
    $exports[$type] = $group_exports;
  }
  return $exports;
}

/**
 * Build the export manifest which integrates with migrate.
 */
function catalyst_prepare_exports_info($export_name, $exports, $groups) {
  // Create a random hash for this export which will be used to limit
  // collisions when importing (eg. in hook_migrate_api())
  $hash = hash('adler32', $export_name . microtime());

  $migrations = array();
  foreach (array_keys($exports) AS $type) {
    if ($type == 'attached_files') continue;
    $group = $groups[$type];
    $migration = $group['migration'];
    // Set the migration group
    $migration['group_name'] = $hash;
    $migration['source_filename'] = $group['export filename'];
    $migration['source_files_directory'] = 'attached-files/' . $type;
    foreach ($group['migration sources'] AS $source_type) {
      if (isset($exports[$source_type])) {
        $migration['source_migrations'][$source_type] = $source_type . '_' . $hash;
      }
    }
    $migrations[$type . '_' . $hash] = $migration;
  }
  return array(
    'api' => 2,
    'groups' => array($hash => array('title' => $export_name)),
    'migrations' => $migrations,
  );
}

/**
 * Flattens attached_files with necessary data for export.
 */
function catalyst_prepare_export_files($grouped_files) {
  $attached_files = array();
  foreach ($grouped_files AS $group => $ungrouped_files) {
    foreach ($ungrouped_files AS $export_id => $files) {
      foreach ($files AS $file) {
        $attached_files[] = (object) array(
          'filepath' => drupal_realpath($file->uri),
          'localname' => implode('/', array('attached-files', $group, $export_id, $file->filename)),
        );
      }
    }
  }
  return $attached_files;
}

/**
 * Expand a single exportable. Attaching dependencies and files.
 */
function catalyst_expand_export($export, $group, $groups) {
  if ($dependencies = module_invoke_all('catalyst_export_dependencies', $export, $group)) {
    foreach ($dependencies AS $dependency_type => $dependency_exports) {
      $dependency_group = $groups[$dependency_type];
      foreach ($dependency_exports AS $dependency_id => $dependency) {
        $dependencies = catalyst_merge_exports($dependencies,
          catalyst_expand_export($dependency, $dependency_group, $groups));
      }
    }
  }

  // Attach files
  $file_fields = _catalyst_export_file_fields();
  if (isset($group['entity_type']) && $file_fields) {
    $wrapper = entity_metadata_wrapper($group['entity_type'], $export);
    foreach ($file_fields AS $field) {
      if (isset($wrapper->{$field}) && !empty($export->{$field})) {
        $field_value = $wrapper->{$field}->value();
        if (isset($field_value['fid'])) {
          $field_value = array($field_value);
        }
        foreach ($field_value AS $file) {
          // Cast file as an object so it doesn't ever get merged
          $id = catalyst_export_entity_id($wrapper);
          $dependencies['attached_files'][$group['type']][$id][$file['fid']] = (object)$file;
        }
      }
    }
  }
  return $dependencies;
}

/**
 * Deep array merge for export/dependencies arrays.
 *
 * Exports should be objects to prevent individual exports from being merged.
 *
 * This differs from array_merge_recusive() and drupal_array_merge_deep() in
 * that it does NOT renumber integar keys (which in this case represent
 * export ids).
 *
 * @see drupal_array_merge_deep()
 */
function catalyst_merge_exports() {
  $arrays = func_get_args();
  $result = array();
  foreach ($arrays AS $array) {
    foreach ($array AS $key => $value) {
      if (isset($result[$key]) && is_array($result[$key]) && is_array($value)) {
        $result[$key] = catalyst_merge_exports($result[$key], $value);
      }
      else {
        $result[$key] = $value;
      }
    }
  }
  return $result;
}

function catalyst_json_encode_exports($exports, $group) {
  $json = array();
  foreach ($exports AS $export) {
    $json[] = (object)$export;
  }
  return catalyst_json_encode($json);
}

function catalyst_export_helper_filter_references($values, $type, $exports) {
  if (is_a($values, 'EntityListWrapper')) {
    $return = array();
    foreach ($values AS $wrapper) {
      $id = catalyst_export_entity_id($wrapper);
      if (!catalyst_export_exists($id, $type, $exports)) {
        continue;
      }
      $return[] = $id;
    }
  }
  else {
    $return = catalyst_export_entity_id($values);
    if (!catalyst_export_exists($return, $type, $exports)) {
      $return = NULL;
    }
  }
  return $return;
}

function catalyst_export_helper_files($values, $entity_id) {
  $return = NULL;
  if (is_a($values, 'EntityListWrapper')) {
    $return = array();
    foreach ($values->value() AS $file) {
      $return[] = $entity_id . '/' . $file['filename'];
    }
  }
  elseif ($file = $values->value()) {
    $return = $entity_id . '/' . $file['filename'];
  }
  return $return;
}

function catalyst_export_entity_id(EntityMetadataWrapper $wrapper) {
  if (isset($wrapper->field__machine)) {
    return $wrapper->field__machine->machine->value();
  }
  return $wrapper->getIdentifier();
}

/**
 * Helper function for checking if an export exists.
 */
function catalyst_export_exists($id, $type, $exports) {
  // First make sure the $type is being exported, then see if the $id
  // is one of the exports
  return isset($exports[$type]) && array_key_exists($id, $exports[$type]);
}

/**
 * Collect a list of all file fields.
 *
 * Used to auto detect attached files in catalyst exports.
 */
function _catalyst_export_file_fields() {
  $fields = &drupal_static(__FUNCTION__);
  if (!isset($fields)) {
    $fields = array();
    $map = field_info_field_map();
    foreach ($map AS $field_name => $field) {
      if ($field['type'] == 'file') {
        $fields[] = $field_name;
      }
    }
  }
  return $fields;
}

/**
 * Add a dependency from the pool of candidates.
 */
function catalyst_add_export(&$exports, $type, $id) {
  $candidates = catalyst_load_export_candidates();
  if (isset($exports[$type][$id])) {
    return TRUE;
  }
  elseif (isset($candidates[$type][$id]['export'])) {
    $exports[$type][$id] = $candidates[$type][$id]['export'];
    return TRUE;
  }
  drupal_set_message(t(
    'Failed to add export (@type:@id) because it is not in the list of candidates',
    array('@type' => $type, '@id' => $id)),
    'warning'
  );
}

/**
 * Load export candidates.
 */
function &catalyst_load_export_candidates($reset = FALSE) {
  $candidates = &drupal_static(__FUNCTION__);
  if ($reset || !isset($candidates)) {
    $groups = catalyst_get_export_groups();
    $candidates = array();
    foreach ($groups AS $type => $group) {
      $candidates[$type] = array();
      foreach (module_invoke_all('catalyst_export_candidates', $group) AS $candidate) {
        $candidate['export'] = (object)$candidate['export'];
        $candidates[$type][$candidate['id']] = $candidate;
      }
    }
  }
  return $candidates;
}

function catalyst_json_encode($var) {
  //$var = drupal_json_decode(drupal_json_encode($var), TRUE);
  return json_encode($var, JSON_PRETTY_PRINT);
}
