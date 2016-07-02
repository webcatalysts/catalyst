<?php

/**
 * @file
 * Catalyst hooks for Catalyst core.
 */

/**
 * Implements hook_catalyst_plugin_info().
 */
function catalyst_core_catalyst_plugin_info() {
  return array(
    'package' => array(
      'title' => t('Packages'),
      'entity_type' => 'catalyst',
      'bundle' => 'package',
      'exportables' => TRUE,
      'migration' => array(
        'class name' => 'CatalystPackageMigration',
      ),
      'crud' => array(
        'admin' => array(
          'path' => 'admin/catalyst/package',
          'menu_item' => array('title' => 'Packages', 'weight' => 50),
        ),
        'add' => array('path' => 'admin/catalyst/package/add'),
        'edit' => array(
          'path' => 'admin/catalyst/package/%eckentity',
          'entity_id' => 3,
        ),
        'delete' => array(
          'path' => 'admin/catalyst/package/%eckentity/delete',
          'entity_id' => 3,
        ),
        'view' => array(
          'path' => 'admin/catalyst/package/%eckentity/view',
          'entity_id' => 3,
          'menu_item' => FALSE,
        ),
      ),
    ),
  );
}

/**
 * Implements hook_catalyst_export_candidates().
 */
function catalyst_core_catalyst_export_candidates($group) {
  if ($group['type'] == 'package') {
    return catalyst_export_entity_candidates($group['type']);
  }
}

/**
 * Implements hook_catalyst_export_dependencies().
 */
function catalyst_core_catalyst_export_dependencies($export, $group) {
  $dependencies = array();
  if (isset($group['entity_type']) && isset($group['bundle'])) {
    $wrapper = entity_metadata_wrapper($group['entity_type'], $export);
    if (isset($wrapper->field__package) && $wrapper->field__package->value()) {
      catalyst_add_export($dependencies, 'package', $wrapper->field__package->getIdentifier());
    }
  }
  return $dependencies;
}

/**
 * Implements hook_catalyst_export_prepare().
 */
function catalyst_core_catalyst_prepare_export($export, $group, $exports) {
  return (object)array('id' => $export->id);
}

/**
 * Implements hook_catalyst_export_alter().
 *
 * Provides export data for fields provided by catalyst_core.
 */
function catalyst_core_catalyst_export_alter(&$export, $original, $group) {
  if (isset($group['entity_type'])) {
    $wrapper = entity_metadata_wrapper($group['entity_type'], $original);
    $setprops = array(
      'title' => 'title',
      'changed' => 'changed',
      'status' => 'status',
      'field__body' => 'content',
      'field__css' => 'css_custom',
      'field__css__layout' => 'css_custom',
      'field__css__page' => 'css_custom',
      'field__debug' => 'debug',
      'field__drupal_processing' => 'drupal_processing',
      'field__html_head' => 'html_head',
      'field__internal' => 'internal',
      'field__files' => 'files_custom',
      'field__js' => 'js_custom',
      'field__js__layout' => 'js_custom',
      'field__js__page' => 'js_custom',
      'field__machine' => 'machine_name',
      'field__onselect' => 'onselect',
      'field__ondeselect' => 'ondeselect',
      'field__package' => 'package',
      'field__preprocess' => 'preprocess_php',
    );
    foreach ($setprops AS $from => $to) {
      if (!isset($export->{$to}) && isset($wrapper->{$from})) {
        switch ($to) {
          case 'package':
            $export->{$to} = $wrapper->{$from}->getIdentifier();
            break;
          case 'files_custom':
            $export->{$to} = catalyst_export_helper_files(
              $wrapper->{$from}, $wrapper->getIdentifier());
            break;
          case 'machine_name':
            $export->{$to} = $wrapper->{$from}->machine->value();
            break;
          case 'content':
          case 'css_custom':
          case 'html_head':
          case 'js_custuom':
          case 'onselect':
          case 'ondeselect':
          case 'preprocess_php':
            if (is_a($wrapper->{$from}, 'EntityStructureWrapper')) {
              $export->{$to} = entity_valval($wrapper->{$from});
              break;
            }
          default:
            $export->{$to} = $wrapper->{$from}->value();
            break;
        }
      }
    }
  }
}
