<?php

/**
 * @file
 */

/**
 * Export selection form.
 */
function catalyst_export_form($form, &$form_state) {
  catalyst_form_load_include($form_state, 'export');

  $form['#export_groups'] = $groups = catalyst_get_export_groups();

  $module_path = drupal_get_path('module', 'catalyst_export');
  $form['#prefix'] = '<div id="catalyst-export-form-wrapper">';
  $form['#suffix'] = '</div>';
  $form['#attached']['library'][] = array('system', 'ui.dialog');
  $form['#attached']['js'][] = $module_path . '/js/jquery.columnizer.js';
  $form['#attached']['js'][] = $module_path . '/js/export-form.js';
  $form['#attached']['css'][] = $module_path . '/css/export-form.css';

  $internal = 'all';
  $package = 'all';

  if (isset($form_state['values']['filters'])) {
    $internal = $form_state['values']['filters']['internal'];
    $package = $form_state['values']['filters']['package'];
  }

  $filters_ajax = array(
    'callback' => 'catalyst_export_form_ajax',
    'method' => 'replace',
    'wrapper' => 'catalyst-export-form-wrapper',
  );
  $form['filters'] = array(
    '#tree' => TRUE,
    '#prefix' => '<div id="catalyst-export=filters" class="container-inline">',
    '#suffix' => '</div>',
  );
  $form['filters']['internal'] = array(
    '#type' => 'select',
    '#title' => t('Realm'),
    '#options' => array(
      'all' => t('All'),
      0 => t('Site'),
      1 => t('Internal'),
    ),
    '#default_value' => $internal,
    '#ajax' => $filters_ajax,
  );
  $package_options = catalyst_export_package_options($internal);
  if ($package_options) {
    $form['filters']['package'] = array(
      '#type' => 'select',
      '#title' => t('Package'),
      '#options' => array(
        'all' => t('All packages'),
        'none' => t('No package'),
      ) + $package_options,
      '#default_value' => $package,
      '#ajax' => $filters_ajax,
    );
  }
  else {
    $form['filters']['package'] = array(
      '#type' => 'hidden',
      '#value' => $package,
    );
  }


  // Exports container
  $form['exports'] = array(
    '#tree' => TRUE,
    '#process' => array('catalyst_export_form_process_exports'),
    '#prefix' => '<div id="catalyst-export-exports-wrapper">',
    '#suffix' => '</div>',
  );

  // Exports AJAX
  $ajax = array(
    'callback' => 'catalyst_export_form_exports_ajax',
    'wrapper' => 'catalyst-export-exports-wrapper',
    'method' => 'replace',
    'effect' => 'fade',
  );


  $candidates = &catalyst_load_export_candidates();
  catalyst_export_filter_candidates($candidates, $internal, $package, $groups);

  foreach ($groups AS $type => $group) {
    if (empty($candidates[$type])) {
      continue;
    }
    // Allow groups to require permission to export
    if (isset($group['permission']) && !user_access($group['permission'])) {
      continue;
    }

    $form['exports'][$type] = array(
      '#type' => 'fieldset',
      '#title' => $group['title'],
      '#tree' => TRUE,
      '#collapsible' => TRUE,
      'items' => array('#tree' => TRUE),
      '#description' => isset($group['description']) ? $group['description'] : NULL,
      '#attributes' => array('class' => array('dontsplit')),
    );

    foreach ($candidates[$type] AS $item) {
      $item_id = $item['id'];
      $form['exports'][$type][$item_id] = array(
        '#type' => 'checkbox',
        '#title' => t('@label [@id]', array('@label' => $item['label'], '@id' => $item_id)),
        '#ajax' => $ajax,
        '#export' => (object)$item['export'],
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
    '#editable' => TRUE,
  );

  // Provide the preview container
  $form['preview'] = array(
    '#prefix' => '<div id="catalyst-export-preview-wrapper">',
    '#suffix' => '</div>',
    '#type' => 'markup',
    '#markup' => NULL,
  );

  // Form actions
  $form['actions'] = array('#type' => 'actions');
  // Fallback support for resolving dependencies without javascript
  $form['actions']['refresh'] = array(
    '#type' => 'button',
    '#value' => t('Refresh dependencies'),
    '#ajax' => $ajax,
  );
  $form['actions']['preview'] = array(
    '#name' => 'op',
    '#type' => 'button',
    '#value' => t('Preview'),
    '#ajax' => array(
      'callback' => 'catalyst_export_form_preview_ajax',
      'wrapper' => 'catalyst-export-preview-wrapper',
    ),
  );
  $form['actions']['download'] = array(
    '#type' => 'submit',
    '#value' => t('Create Export'),
  );
  return $form;
}

function catalyst_export_form_process_exports($element, &$form_state, &$form) {
  // Processing only necessary if input provided
  if (!isset($form_state['values']['exports'])) {
    return $element;
  }

  $groups = $form['#export_groups'];

  // Build list of selected exports and dependencies separately
  $exports = catalyst_export_form_prepare_selections($form, $form_state);
  $dependencies = array();
  foreach (array_keys($exports) AS $type) {
    foreach ($exports[$type] AS $export) {
      $dependencies = catalyst_merge_exports($dependencies,
        catalyst_expand_export($export, $groups[$type], $groups));
    }
  }

  foreach (element_children($element) AS $type) {
    $group = $form['#export_groups'][$type];
    foreach (element_children($element[$type]) AS $item_id) {
      if ($item_id == 'attached_files') continue;
      if (catalyst_export_exists($item_id, $type, $dependencies)) {
        $element[$type][$item_id]['#default_value'] = 1;
        $element[$type][$item_id]['#disabled'] = 1;
      }
    }

    if (isset($dependencies['attached_files'][$type])) {
      $links = array();
      foreach ($dependencies['attached_files'][$type] AS $item_id => $files) {
        foreach ($files AS $fid => $file) {
          $links[$fid] = array(
            'href' => file_create_url($file->uri),
            'title' => $file->filename,
            'attributes' => array('target' => '_blank'),
          );
        }
      }
      $element[$type]['attached_files'] = array(
        '#prefix' => '<div class="catalyst-export-attached-files">' .
          '<h5>' . t('Attached Files (@num)', array('@num' => count($links))) . '</h5>',
        '#suffix' => '</div>',
        '#weight' => 1000,
        '#collapsible' => FALSE,
        '#markup' => theme('links', array('links' => $links)),
        '#weight' => 1000,
      );
    }
  }
  return $element;
}

function catalyst_export_form_preview_ajax($form, $form_state) {
  $groups = $form['#export_groups'];
  $selections = catalyst_export_form_prepare_selections($form, $form_state);
  $data = catalyst_build_export_data($selections, $groups, array(
    'title' => $form_state['values']['export_name'],
    'group' => $form_state['values']['export_filename'],
  ));
  dsm($data);
  return $form['preview'];
}

function catalyst_export_form_ajax($form, $form_state) {
  return $form;
}

function catalyst_export_form_exports_ajax($form, $form_state) {
  return $form['exports'];
}

function catalyst_export_form_prepare_selections($form, $form_state) {
  $selections = array();
  foreach ($form_state['values']['exports'] AS $type => $values) {
    if ($ids = array_keys(array_filter($values))) {
      foreach ($ids AS $id) {
        $selections[$type][$id] = $form['exports'][$type][$id]['#export'];
      }
    }
  }
  return $selections;
}

function catalyst_export_form_submit($form, &$form_state) {
  //$groups = catalyst_export_get_groups();
  $groups = $form['#export_groups'];
  $export_name = $form_state['values']['export_name'];
  $export_filename = $form_state['values']['export_filename'] . '.zip';

  $selections = catalyst_export_form_prepare_selections($form, $form_state);
  $build = catalyst_build_export_data($selections, $groups, array(
    'title' => $export_name,
    'group' => $form_state['values']['export_filename'],
  ));

  // archive to be cleaned up at the end.
  $cleanup = &drupal_static('catalyst_export_cleanup');
  $cleanup['unlink'] = array();
  $cleanup['rmdir'] = array();

  $tmp_archive_uri = drupal_tempnam('temporary://', 'zip_');
  $tmp_archive = drupal_realpath($tmp_archive_uri);
  $cleanup['unlink'][] = $tmp_archive_uri;

  $archiver = new ZipArchive;
  if ($archiver->open($tmp_archive, ZipArchive::OVERWRITE) !== TRUE) {
    form_set_error('', 'Failed to create archive: ' . $tmp_archive);
    return;
  }

  // Add attached files to the archive
  if (isset($build['exports']['attached_files'])) {
    foreach ($build['exports']['attached_files'] AS $file) {
      $archiver->addFile($file->filepath, $file->localname);
    }
    unset($build['exports']['attached_files']);
  }

  foreach ($build['exports'] AS $type => $export_items) {
    $group = $groups[$type];
    $group_export_data = call_user_func($group['export callback'], $export_items, $group);
    if (!$archiver->addFromString($group['export filename'], $group_export_data)) {
      form_set_error('', 'Failed to add group export data');
      return;
    }
  }

  if (!$archiver->addFromString('catalyst.json', catalyst_json_encode($build['info']))) {
    form_set_error('', 'Failed to add migrate_api.json');
    return;
  }

  if ($archiver->close() === FALSE) {
    form_set_error('', 'Archiver failed to close.');
    return;
  }

  file_transfer($tmp_archive_uri, array(
    'Content-Type' => 'application/octet-stream',
   'Content-Disposition' => 'attachment; filename="' . $export_filename . '"',
   'Content-Length' => filesize($tmp_archive)));

  drupal_exit();
}

function catalyst_export_package_options($internal = 0) {
  $options = array();
  $packages = array();
  if ($internal === FALSE) {
    //$packages = catalyst_load(FALSE, array('type' => 'package'));
    $packages = entity_load('catalyst', FALSE, array('type' => 'package'));
  }
  else {
    $query = new EntityFieldQuery;
    $query->entityCondition('entity_type', 'catalyst')
      ->entityCondition('bundle', 'package')
      ->fieldCondition('field__internal', 'value', $internal, '=');
    $result = $query->execute();
    if (isset($result['catalyst'])) {
      $packages = entity_load('catalyst', array_keys($result['catalyst']));
    }
  }

  foreach ($packages AS $package) {
    $options[$package->id] = filter_xss_admin($package->title);
  }
  return $options;
}

function catalyst_export_filter_candidates(&$candidates, $internal, $package, $groups) {
  if ($internal === 'all' && $package === 'all') {
    return $candidates;
  }
  foreach (array_keys($candidates) AS $type) {
    $group = $groups[$type];
    foreach ($candidates[$type] AS $id => $candidate) {
      if (isset($group['entity_type']) && isset($group['bundle'])) {
        $wrapper = entity_metadata_wrapper($group['entity_type'], $candidate['export']);
        switch (true) {
          case $internal !== 'all' && catalyst_export_filter_candidate_internal($wrapper, $internal):
          case $package !== 'all' && catalyst_export_filter_candidate_package($wrapper, $package):
            unset($candidates[$type][$id]);
        }
      }
      elseif (intval($internal) === 1 || !in_array($package, array('all', 'none'))) {
        unset($candidates[$type][$id]);
      }
    }
  }
}

function catalyst_export_filter_candidate_package($wrapper, $package) {
  switch (true) {
    case $wrapper->getBundle() == 'package':
      // Filter packages
      return $package == 'none' || $package != $wrapper->getIdentifier();
    case $package == 'none':
      // Filter entities with a package
      return isset($wrapper->field__package) && $wrapper->field__package->value();
    default:
      return !isset($wrapper->field__package) || $wrapper->field__package->getIdentifier() != $package;
  }
}

function catalyst_export_filter_candidate_internal($wrapper, $internal) {
  switch (intval($internal)) {
    case 0:
      return isset($wrapper->field__internal) && $wrapper->field__internal->value() != 0;
    case 1:
      return !isset($wrapper->field__internal) || $wrapper->field__internal->value() == 0;
  }
}

function _catalyst_export_dummy_exists() {
  return FALSE;
}
