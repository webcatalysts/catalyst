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

  // Exported field_base: 'field_block_content'.
  $field_bases['field_block_content'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_block_content',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_block_machine'.
  $field_bases['field_block_machine'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_block_machine',
    'indexes' => array(
      'machine' => array(
        0 => 'machine',
      ),
    ),
    'locked' => 0,
    'module' => 'machine',
    'settings' => array(
      'max_length' => 255,
      'unique_per' => 'field',
    ),
    'translatable' => 0,
    'type' => 'machine',
  );

  // Exported field_base: 'field_block_placements'.
  $field_bases['field_block_placements'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_block_placements',
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

  // Exported field_base: 'field_block_preprocess'.
  $field_bases['field_block_preprocess'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_block_preprocess',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_catalyst_custom_css'.
  $field_bases['field_catalyst_custom_css'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_catalyst_custom_css',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_catalyst_custom_js'.
  $field_bases['field_catalyst_custom_js'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_catalyst_custom_js',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_catalyst_includes_css'.
  $field_bases['field_catalyst_includes_css'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_catalyst_includes_css',
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
          'stylesheet' => 'stylesheet',
        ),
      ),
      'target_type' => 'catalyst',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_catalyst_includes_js'.
  $field_bases['field_catalyst_includes_js'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_catalyst_includes_js',
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
          'javascript' => 'javascript',
        ),
      ),
      'target_type' => 'catalyst',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
