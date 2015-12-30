<?php

/**
 * @file
 */

/**
 * Export selection form.
 */
function catalyst_export_form($form, &$form_state) {
  $groups = catalyst_export_get_groups();

  $ajax = array(
    'callback' => 'catalyst_export_form_ajax_callback',
    'wrapper' => 'catalyst-export-form-wrapper',
    'method' => 'replace',
    'effect' => 'fade',
  );
  //$form['#theme'] = 'catalyst_export_form';
  $form['#prefix'] = '<div id="catalyst-export-form-wrapper">';
  $form['#suffix'] = '</div>';

  $form['#process'][] = 'catalyst_export_form_process';
  $form['#export_groups'] = $groups;

  $exports = array();

  foreach ($groups AS $type => $group) {
    //$group += array();

    if (isset($group['permission']) && !user_access($group['permission'])) {
      // Need permission to call the XML feeds provided by views
      // May want to set a warning here
      continue;
    }

    $form[$type] = array(
      '#type' => 'fieldset',
      '#tree' => TRUE,
      '#title' => $group['title'],
    );

    $items = module_invoke_all('catalyst_export_candidates', $type, $group);
    foreach ($items AS $entity) {
      $wrapper = entity_metadata_wrapper($group['entity_type'], $entity);
      $entity_id = $wrapper->getIdentifier();
      $form[$type][$entity_id] = array(
        '#type' => 'checkbox',
        '#title' => t('@label [@id]', array('@label' => $wrapper->label(), '@id' => $entity_id)),
        '#ajax' => $ajax,
        '#export_entity' => $entity,
      );
    }
  }

  $form['options'] = array();
  $form['options']['export_name'] = array(
    '#title' => t('Export name'),
    '#type' => 'textfield',
    '#default_value' => variable_get('site_name', t('Catalyst')),
    '#size' => 40,
  );
  $form['options']['export_filename'] = array(
    '#title' => t('Export filename'),
    '#type' => 'machine_name',
    '#size' => 40,
    '#machine_name' => array(
      'exists' => '_catalyst_export_dummy_exists',
      'source' => array('options','export_name'),
    ),
    '#field_suffix' => '.zip',
  );
  return $form;
}

function catalyst_export_form_ajax_callback($form, $form_state) {
  return $form;
}

function catalyst_export_form_process($form, &$form_state) {
  $exports = array();
  $dependencies = array();

  foreach ($form['#export_groups'] AS $type => $group) {
    if (isset($form_state['values'][$type]) && $_exports = array_keys(array_filter($form_state['values'][$type]))) {
      foreach ($_exports AS $id) {
        $exports[$type][$id] = $form[$type][$id]['#export_entity'];
        $dependencies = catalyst_export_array_merge($dependencies, catalyst_export_expand_item($type, $exports[$type][$id], $group));
      }
    }
  }
  foreach ($form['#export_groups'] AS $type => $group) {
    if (!isset($dependencies[$type]) || !is_array($form[$type])) {
      continue;
    }
    foreach (element_children($form[$type]) AS $i) {
      if (array_key_exists($i, $dependencies[$type])) {
        $form[$type][$i]['#default_value'] = 1;
        $form[$type][$i]['#disabled'] = 1;
      }
    }
  }
  if (isset($dependencies['attached_files'])) {
    $form['attached_files'] = array(
      '#type' => 'fieldset',
      '#title' => t('Attached files'),
    );
    $links = array();
    foreach ($dependencies['attached_files'] AS $type => $items) {
      $links = array();
      foreach ($items AS $id => $files) {
        foreach ($files AS $fid => $file) {
          $links[$fid] = array(
            'href' => file_create_url($file->uri),
            'title' => $file->filename,
            'attributes' => array('target' => '_blank'),
          );
        }
      }
      $form['attached_files'][$type] = array(
        '#prefix' => '<div><strong>' . $groups[$type]['title'] . '</div>',
        '#type' => 'markup',
        '#markup' => theme('links', array('links' => $links)),
      );
    }
  }

  $form['actions'] = array(
    '#type' => 'actions',
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Create Export'),
  );
  return $form;
}

function catalyst_export_form_submit($form, &$form_state) {
  $exports = array();
  foreach ($form['#export_groups'] AS $type => $group) {
    if (isset($form_state['values'][$type]) && $_exports = array_keys(array_filter($form_state['values'][$type]))) {
      foreach ($_exports AS $id) {
        $exports[$type][$id] = $form[$type][$id]['#export_entity'];
        $exports = catalyst_export_array_merge($exports, catalyst_export_expand_item($type, $exports[$type][$id], $group));
      }
    }
  }

  $cleanup = &drupal_static('catalyst_export_cleanup');
  $cleanup['unlink'] = array();
  $cleanup['rmdir'] = array();

  $export_name = $form_state['values']['export_name'];
  $export_filename = $form_state['values']['export_filename'] . '.zip';
  $export_hash = md5(microtime());

  $export_dir_uri = file_build_uri('catalyst-export/' . $export_hash);
  drupal_mkdir($export_dir_uri, NULL, TRUE);
  $cleanup['rmdir'][] = $export_dir_uri;
  $export_dir = drupal_realpath($export_dir_uri);

  $export_archive_uri = file_build_uri('catalyst-export/' . $export_hash . '.zip');
  $export_archive = drupal_realpath($export_archive_uri);

  $groups = catalyst_export_get_groups();
  $migrate_api = array(
    'groups' => array(
      $export_hash => array(
        'title' => $export_name,
      ),
    ),
  );

  // Create the tmp dir for building the export

  //$archiver = new ArchiverZip($export_archive);
  $archiver = new ZipArchive;
  if ($archiver->open($export_archive, ZIPARCHIVE::CREATE) !== TRUE) {
    form_set_error('', 'Failed to create archive: ' . $export_archive);
    return;
  }

  $cleanup['unlink'][] = $export_archive_uri;

  if (isset($exports['attached_files'])) {
    $attached_files = $exports['attached_files'];
    foreach ($attached_files AS $type => $items) {
      foreach ($items AS $id => $files) {
        foreach ($files AS $file) {
          $archiver->addFile(
            drupal_realpath($file->uri),
            implode('/', array($type, $id, $file->filename))
          );
        }
      }
    }
    unset($exports['attached_files']);
  }

  foreach ($exports AS $type => $items) {
    $group = $groups[$type] + array(
      'feed_id_parameter' => 'ids',
      'feed_id_separator' => '+',
    );

    if (!isset($group['feed_path'])) {
      $archiver->close();
      form_set_error('', 'No feed path for group: ' . $group['title']);
      return;
    }

    $ids = array_keys($items);
    $feed_url = url($group['feed_path'], array(
      'query' => array(
        $group['feed_id_parameter'] => implode($group['feed_id_separator'], $ids),
      ),
      'absolute' => TRUE,
    ));


    // Pass the cookie onto the request
    $cookiestring = "";
    foreach ($_COOKIE as $key => $cookie) {
      $cookiestring .= $key .'='. urlencode($cookie) .';';
    }

    $feed_result = drupal_http_request($feed_url, array('headers' => array('Cookie' => $cookiestring)));
    if (isset($feed_result->error)) {
      $archiver->close();
      form_set_error('', t('The %title feed at @url resulted returned the following error: %error', array(
        '%title' => $group['title'],
        '@url' => $feed_url,
        '%error' => $feed_result->error,
      )));
      return;
    }

    $fp = fopen($export_dir . '/' . $type . '.xml', 'w');
    fwrite($fp, $feed_result->data);
    fclose($fp);
    $archiver->addFile(
      $export_dir . '/' . $type . '.xml',
      $type. '/' . $type . '.xml'
    );
    $cleanup['unlink'][] = $export_dir_uri . '/' . $type . '.xml';

    $migrate_api['migrations'][$type . '_' . $export_hash] = $group['migration'] + array(
      'group_name' => $export_hash,
      'xml_filename' => $type . '.xml',
      'data_directory' => $type,
      'files_directory' => $type . '/attached-files',
    );
  }

  // Create the json file
  $fp = fopen($export_dir . '/migrate_api.json', 'w');
  fwrite($fp, drupal_json_encode($migrate_api));
  fclose($fp);
  $cleanup['unlink'][] = $export_dir_uri . '/migrate_api.json';

  if (!$archiver->addFile($export_dir . '/migrate_api.json', 'migrate_api.json')) {
    form_set_error('', 'Failed to add migrate_api.json');
    return;
  }

  if ($archiver->close() === FALSE) {
    form_set_error('', 'Archiver failed to close.');
    return;
  }

  file_transfer($export_archive_uri, array(
    'Content-Type' => 'application/octet-stream',
   'Content-Disposition' => 'attachment; filename="' . $export_filename . '"',
   'Content-Length' => filesize($export_archive)));

  drupal_exit();
}

function catalyst_export_expand_item($type, $entity, $group) {
  if ($dependencies = module_invoke_all('catalyst_export_dependencies', $type, $entity, $group)) {
    $groups = catalyst_export_get_groups();
    foreach ($dependencies AS $_type => $entities) {
      foreach ($entities AS $_entity) {
        $dependencies = catalyst_export_array_merge($dependencies, catalyst_export_expand_item($_type, $_entity, $groups[$_type]));
      }
    }
  }

  // Attach files
  if ($file_fields = _catalyst_export_file_fields()) {
    $wrapper = entity_metadata_wrapper($group['entity_type'], $entity);
    foreach ($file_fields AS $field) {
      if (isset($wrapper->{$field}) && !empty($entity->{$field})) {
        $field_value = $wrapper->{$field}->value();
        if (isset($field_value['fid'])) {
          $field_value = array($field_value);;
        }
        foreach ($field_value AS $file) {
          // Cast file as an object so it doesn't ever get merged
          $dependencies['attached_files'][$type][$wrapper->getIdentifier()][$file['fid']] = (object)$file;
        }
      }
    }
  }
  return $dependencies;
}

function catalyst_export_get_groups() {
  $groups = &drupal_static(__FUNCTION__);

  if (!isset($groups)) {
    $groups = module_invoke_all('catalyst_export_groups');
    uasort($groups, 'drupal_sort_weight');
  }
  return $groups;
}

function catalyst_export_array_merge() {
  $arrays = func_get_args();
  $result = array();
  foreach ($arrays AS $array) {
    foreach ($array AS $key => $value) {
      if (isset($result[$key]) && is_array($result[$key]) && is_array($value)) {
        $result[$key] = catalyst_export_array_merge($result[$key], $value);
      }
      else {
        $result[$key] = $value;
      }
    }
  }
  return $result;
}

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

function _catalyst_export_dummy_exists() {
  return FALSE;
}
