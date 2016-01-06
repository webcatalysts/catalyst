<?php

/**
 * @file
 * Catalyst hook implementations for Catalyst Media
 */

/**
 * Implements hook_catalyst_plugin_info().
 */
function catalyst_media_catalyst_plugin_info() {
  $defaults = array(
    'entity_type' => 'catalyst',
    'exportables' => TRUE,
  );
  return array(
    'stylesheet' => array(
      'title' => t('Stylesheets'),
      'bundle' => 'stylesheet',
      'migration' => array(
        'class_name' => 'CatalystMediaStylesheetMigration',
      ),
      'migration sources' => array('file'),
    ) + $defaults,
    'javascript' => array(
      'title' => t('Javascripts'),
      'bundle' => 'javascript',
      'migration' => array(
        'class_name' => 'CatalystMediaJavascriptMigration',
      ),
    ) + $defaults,
    'file' => array(
      'title' => t('Shared Files'),
      'bundle' => 'file',
      'migration' => array(
        'class_name' => 'CatalystMediaFileMigration',
      ),
    ) + $defaults,
  );
}

/**
 * Implements hook_catalyst_export_candidates().
 */
function catalyst_media_catalyst_export_candidates($group) {
  if (in_array($group['type'], array('stylesheet', 'javascript', 'file'))) {
    return catalyst_export_entity_candidates($group['type']);
  }
}

/**
 * Implements hook_catalyst_export_dependencies().
 */
function catalyst_media_catalyst_export_dependencies($export, $group) {
  if (isset($group['entity_type'])) {
    $dependencies = array();
    $fields = array(
      // field => type
      'field_catalyst_includes_css' => 'stylesheet',
      'field_cpage_includes_css' => 'stylesheet',
      'field_layout_includes_css' => 'stylesheet',
      'field_catalyst_includes_js' => 'javascript',
      'field_cpage_includes_js' => 'javascript',
      'field_layout_includes_js' => 'javascript',
      'field_catalyst_shared_files' => 'file',
    );
    $wrapper = entity_metadata_wrapper($group['entity_type'], $export);
    foreach ($fields AS $field => $_type) {
      if (isset($wrapper->{$field})) {
        foreach ($wrapper->{$field} AS $item) {
          catalyst_add_export($dependencies, $_type, $item->getIdentifier());
        }
      }
    }
    return $dependencies;
  }
}

/**
 * Implements hook_catalyst_prepare_export().
 */
function catalyst_media_catalyst_prepare_export($export, $group, $exports) {
  $wrapper = entity_metadata_wrapper($group['entity_type'], $export);
  $export = array(
    'id' => $wrapper->getIdentifier(),
    'title' => $wrapper->label(),
    'created' => $wrapper->created->value(),
    'changed' => $wrapper->changed->value(),
    'machine_name' => $wrapper->field_media_machine->machine->value(),
    'media_type' => $wrapper->field_media_type->value(),
    'media_path' => $wrapper->field_media_path->value(),
  );
  if (in_array($group['type'], array('stylesheet', 'javascript'))) {
    $export['content'] = entity_valval($wrapper->field_media_content);
  }
  switch ($group['type']) {
    case 'stylesheet':
      $export['files_custom'] = catalyst_export_helper_files(
        $wrapper->field_catalyst_custom_files, $wrapper->getIdentifier());
      $export['files_shared'] = catalyst_export_helper_filter_references(
        $wrapper->field_catalyst_shared_files, 'file', $exports);
      break;
    case 'javascript':
      $export['defer'] = $wrapper->field_javascript_defer->value();
      $export['scope'] = $wrapper->field_javascript_scope->value();
      break;
    case 'file':
      $export['file_path'] = catalyst_export_helper_files(
        $wrapper->field_media_file, $wrapper->getIdentifier());
      break;
  }
  return (object)$export;
}
