<?php

/**
 * @file
 * Catalyst hook implmentations for Catalyst Doctype.
 */


/**
 * Implements hook_catalyst_plugin_info().
 */
function catalyst_doctype_catalyst_plugin_info() {
  return array(
    'doctype' => array(
      'title' => t('Document types'),
      'entity_type' => 'catalyst',
      'bundle' => 'doctype',
      'exportables' => TRUE,
      'migration' => array(
        'class_name' => 'CatalystDoctypeMigration',
      ),
      'crud' => array(
        'admin' => array(
          'path' => 'admin/catalyst/doctype',
          'menu_item' => array(
            'title' => 'Document Types',
            'weight' => 80,
          ),
        ),
        'add' => array('path' => 'admin/catalyst/doctype/add'),
        'edit' => array(
          'path' => 'admin/catalyst/doctype/%eckentity',
          'entity_id' => 3,
        ),
        'delete' => array(
          'path' => 'admin/catalyst/doctype/%eckentity/delete',
          'entity_id' => 3,
        ),
        'view' => array(
          'path' => 'admin/catalyst/doctype/%eckentity/view',
          'entity_id' => 3,
          'menu_item' => FALSE,
        ),
      ),
    ),
  );
}

/**
 * Implements hook_catalyst_exportables().
 */
function catalyst_doctype_catalyst_export_candidates($group) {
  if ($group['type'] == 'doctype') {
    return catalyst_export_entity_candidates($group['type']);
  }
}

/**
 * Implements hook_catalyst_export_dependencies().
 */
function catalyst_doctype_catalyst_export_dependencies($export, $group) {
  if (isset($group['entity_type'])) {
    $dependencies = array();
    // Determine dependencies for items that rely on doctypes
    if (isset($export->field__doctype)) {
      $wrapper = entity_metadata_wrapper($group['entity_type'], $export);
      $doctype = $wrapper->field__doctype;
      catalyst_add_export($dependencies, 'doctype', $doctype->getIdentifier());
    }
    return $dependencies;
  }
}

/**
 * Implements hook_catalyst_prepare_export().
 */
function catalyst_doctype_catalyst_prepare_export($export, $group, $exports) {
  $wrapper = entity_metadata_wrapper($group['entity_type'], $export);
  return (object) array(
    'charset' => $wrapper->field__doctype_charset->value(),
    'http_content_type' => $wrapper->field__doctype_content_type->value(),
  );
}

/**
 * Implements hook_catalyst_export_alter().
 */
function catalyst_doctype_catalyst_export_alter(&$export, $original, $group, $exports) {
  if (isset($group['entity_type'])) {
    $wrapper = entity_metadata_wrapper($group['entity_type'], $export);
    if (!isset($export->doctype) && isset($wrapper->doctype)) {
      $export->doctype = catalyst_export_helper_filter_references($wrapper->field__doctype, 'doctype', $exports);
    }
  }
}
