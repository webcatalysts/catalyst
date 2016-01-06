<?php
/**
 * @file
 * catalyst_template.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function catalyst_template_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field__template_bundle'.
  $field_bases['field__template_bundle'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field__template_bundle',
    'indexes' => array(
      'machine' => array(
        0 => 'machine',
      ),
    ),
    'locked' => 0,
    'module' => 'machine',
    'settings' => array(
      'max_length' => 32,
      'unique_per' => '',
    ),
    'translatable' => 0,
    'type' => 'machine',
  );

  // Exported field_base: 'field__template_entity_type'.
  $field_bases['field__template_entity_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field__template_entity_type',
    'indexes' => array(
      'machine' => array(
        0 => 'machine',
      ),
    ),
    'locked' => 0,
    'module' => 'machine',
    'settings' => array(
      'max_length' => 128,
      'unique_per' => '',
    ),
    'translatable' => 0,
    'type' => 'machine',
  );

  return $field_bases;
}
