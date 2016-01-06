<?php
/**
 * @file
 * catalyst_block.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function catalyst_block_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field__blockplacements__block'.
  $field_bases['field__blockplacements__block'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field__blockplacements__block',
    'indexes' => array(
      'layout_id' => array(
        0 => 'layout_id',
      ),
      'region' => array(
        0 => 'region',
      ),
    ),
    'locked' => 0,
    'module' => 'catalyst_block',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'block_placement_block',
  );

  // Exported field_base: 'field__blocks_related'.
  $field_bases['field__blocks_related'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field__blocks_related',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 1,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'block' => 'block',
        ),
      ),
      'target_type' => 'catalyst',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field__blockplacements__layout'.
  $field_bases['field__blockplacements__layout'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field__blockplacements__layout',
    'indexes' => array(
      'block_id' => array(
        0 => 'block_id',
      ),
      'region' => array(
        0 => 'region',
      ),
    ),
    'locked' => 0,
    'module' => 'catalyst_block',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'block_placement_layout',
  );

  // Exported field_base: 'field__blockplacements__layfield'.
  $field_bases['field__blockplacements__layfield'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field__blockplacements__layfield',
    'indexes' => array(
      'block_id' => array(
        0 => 'block_id',
      ),
      'region' => array(
        0 => 'region',
      ),
    ),
    'locked' => 0,
    'module' => 'catalyst_block',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'block_placement_layout_field',
  );

  return $field_bases;
}
