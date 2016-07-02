<?php
/**
 * @file
 * catalyst_core.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function catalyst_core_eck_bundle_info() {
  $items = array(
    'catalyst_package' => array(
      'machine_name' => 'catalyst_package',
      'entity_type' => 'catalyst',
      'name' => 'package',
      'label' => 'Package',
      'config' => array(
        'managed_properties' => array(
          'title' => 'title',
          'created' => 0,
          'changed' => 0,
          'language' => 0,
        ),
      ),
    ),
  );
  return $items;
}

/**
 * Implements hook_eck_entity_type_info().
 */
function catalyst_core_eck_entity_type_info() {
  $items = array(
    'catalyst' => array(
      'name' => 'catalyst',
      'label' => 'catalyst',
      'properties' => array(
        'title' => array(
          'label' => 'Title',
          'type' => 'text',
          'behavior' => 'title',
        ),
        'created' => array(
          'label' => 'Created',
          'type' => 'integer',
          'behavior' => 'created',
        ),
        'changed' => array(
          'label' => 'Changed',
          'type' => 'integer',
          'behavior' => 'changed',
        ),
        'language' => array(
          'label' => 'Entity language',
          'type' => 'language',
          'behavior' => 'language',
        ),
      ),
    ),
  );
  return $items;
}
