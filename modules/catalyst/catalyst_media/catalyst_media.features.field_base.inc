<?php
/**
 * @file
 * catalyst_media.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function catalyst_media_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_file_machine'.
  $field_bases['field_file_machine'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_file_machine',
    'indexes' => array(
      'machine' => array(
        0 => 'machine',
      ),
    ),
    'locked' => 0,
    'module' => 'machine',
    'settings' => array(
      'machine_max_length' => 255,
      'unique_values_per' => 'entity',
    ),
    'translatable' => 0,
    'type' => 'machine',
  );

  // Exported field_base: 'field_javascript_defer'.
  $field_bases['field_javascript_defer'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_javascript_defer',
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

  // Exported field_base: 'field_javascript_machine'.
  $field_bases['field_javascript_machine'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_javascript_machine',
    'indexes' => array(
      'machine' => array(
        0 => 'machine',
      ),
    ),
    'locked' => 0,
    'module' => 'safeword',
    'settings' => array(
      'allow_machine_changes' => 0,
      'complete_path_label' => 'Complete path',
      'machine_description' => 'Unique machine name for the Javascript',
      'machine_label' => 'Machine name',
      'max_length' => 255,
      'replace_pattern' => '(--|<[^<>]+>|[^/a-z0-9-])+',
      'replace_value' => '-',
      'show_complete_path' => 0,
      'unique' => 1,
    ),
    'translatable' => 0,
    'type' => 'safeword_title',
  );

  // Exported field_base: 'field_javascript_scope'.
  $field_bases['field_javascript_scope'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_javascript_scope',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'header' => 'Header',
        'footer' => 'Footer',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_media_content'.
  $field_bases['field_media_content'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_media_content',
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

  // Exported field_base: 'field_media_file'.
  $field_bases['field_media_file'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_media_file',
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'display_default' => 0,
      'display_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  // Exported field_base: 'field_media_path'.
  $field_bases['field_media_path'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_media_path',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_media_type'.
  $field_bases['field_media_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_media_type',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'custom' => 'Custom',
        'local' => 'Local',
        'remote' => 'Remote',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_stylesheet_machine'.
  $field_bases['field_stylesheet_machine'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_stylesheet_machine',
    'indexes' => array(
      'machine' => array(
        0 => 'machine',
      ),
    ),
    'locked' => 0,
    'module' => 'machine',
    'settings' => array(
      'machine_max_length' => 255,
      'unique_values_per' => 'entity',
    ),
    'translatable' => 0,
    'type' => 'machine',
  );

  // Exported field_base: 'field_stylesheet_media'.
  $field_bases['field_stylesheet_media'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_stylesheet_media',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'all' => 'All',
        'screen' => 'Screen',
        'print' => 'Print',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
