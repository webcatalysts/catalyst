<?php
/**
 * @file
 * catalyst_layout.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function catalyst_layout_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field__layout'.
  $field_bases['field__layout'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field__layout',
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
          'layout' => 'layout',
        ),
      ),
      'target_type' => 'catalyst',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field__layout_drupal_css'.
  $field_bases['field__layout_drupal_css'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field__layout_drupal_css',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        -100 => 'Enable system stylesheets',
        0 => 'Enable module stylesheets',
        100 => 'Enable theme stylesheets',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'field__layout_drupal_js'.
  $field_bases['field__layout_drupal_js'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field__layout_drupal_js',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        -100 => 'Enable Drupal Libraries',
        0 => 'Enable Standard Scripts (added by modules)',
        100 => 'Enable Theme Scripts (added by themes, usually not applicable)',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  // Exported field_base: 'field__layout_page_title_pattern'.
  $field_bases['field__layout_page_title_pattern'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field__layout_page_title_pattern',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 128,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field__layout_regions'.
  $field_bases['field__layout_regions'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field__layout_regions',
    'indexes' => array(
      'machine' => array(
        0 => 'machine',
      ),
    ),
    'locked' => 0,
    'module' => 'machine',
    'settings' => array(
      'max_length' => 32,
      'unique_per' => 'entity',
      'unique_text' => 1,
    ),
    'translatable' => 0,
    'type' => 'machine_with_text',
  );

  // Exported field_base: 'field__layout_show_messages'.
  $field_bases['field__layout_show_messages'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field__layout_show_messages',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
