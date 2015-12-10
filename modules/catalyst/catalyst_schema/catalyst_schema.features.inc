<?php
/**
 * @file
 * catalyst_schema.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function catalyst_schema_eck_bundle_info() {
  $items = array(
    'catalyst_schema' => array(
      'machine_name' => 'catalyst_schema',
      'entity_type' => 'catalyst',
      'name' => 'schema',
      'label' => 'Schema',
      'config' => array(),
    ),
  );
  return $items;
}
