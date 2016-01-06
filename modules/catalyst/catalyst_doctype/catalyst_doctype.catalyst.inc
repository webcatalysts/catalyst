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
    if (isset($export->field_layout_doctype)) {
      $wrapper = entity_metadata_wrapper($group['entity_type'], $export);
      $doctype = $wrapper->field_layout_doctype;
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
    'id' => $wrapper->getIdentifier(),
    'title' => $wrapper->title->value(),
    'created' => $wrapper->created->value(),
    'changed' => $wrapper->changed->value(),
    'content' => entity_valval($wrapper->field_doctype_content),
    'charset' => $wrapper->field_doctype_charset->value(),
    'http_content_type' => $wrapper->field_doctype_content_type->value(),
    'drupal_processing' => $wrapper->field_catalyst_drupal_processing->value(),
    'preprocess_php' => entity_valval($wrapper->field_doctype_preprocess),
    'onselect' => entity_valval($wrapper->field_doctype_onselect),
    'ondeselect' => entity_valval($wrapper->field_doctype_ondeselect),
  );
}
