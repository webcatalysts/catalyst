<?php
/**
 * @file
 * catalyst_media.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function catalyst_media_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_file_advanced|catalyst|file|form';
  $field_group->group_name = 'group_file_advanced';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'file';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '5',
    'children' => array(
      0 => 'field__internal',
      1 => 'field__package',
      2 => 'group_file_help',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Advanced',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-file-advanced field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_file_advanced|catalyst|file|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_file_content|catalyst|stylesheet|form';
  $field_group->group_name = 'group_file_content';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'stylesheet';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_file_tabs';
  $field_group->data = array(
    'label' => 'Stylesheet content',
    'weight' => '2',
    'children' => array(
      0 => 'field__body',
      1 => 'field__machine',
      2 => 'field__media_path',
      3 => 'field__media_stylesheet_media',
      4 => 'field__media_type',
      5 => 'title',
      6 => 'group_stylesheet_advanced',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-file-content field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_file_content|catalyst|stylesheet|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_file_files|catalyst|stylesheet|form';
  $field_group->group_name = 'group_file_files';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'stylesheet';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_file_tabs';
  $field_group->data = array(
    'label' => 'Media/Files',
    'weight' => '3',
    'children' => array(
      0 => 'field__files',
      1 => 'field__media_files',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-file-files field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_file_files|catalyst|stylesheet|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_file_help|catalyst|file|form';
  $field_group->group_name = 'group_file_help';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'file';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_file_advanced';
  $field_group->data = array(
    'label' => 'Custom Help/Instructions',
    'weight' => '13',
    'children' => array(
      0 => 'field__admin_notes',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Custom Help/Instructions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-file-help field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_file_help|catalyst|file|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_file_tabs|catalyst|stylesheet|form';
  $field_group->group_name = 'group_file_tabs';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'stylesheet';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_file_content',
      1 => 'group_file_files',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-file-tabs field-group-htabs',
      ),
    ),
  );
  $field_groups['group_file_tabs|catalyst|stylesheet|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_javascript_advanced|catalyst|javascript|form';
  $field_group->group_name = 'group_javascript_advanced';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'javascript';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '7',
    'children' => array(
      0 => 'field__internal',
      1 => 'field__package',
      2 => 'group_javascript_help',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Advanced',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-javascript-advanced field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_javascript_advanced|catalyst|javascript|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_javascript_help|catalyst|javascript|form';
  $field_group->group_name = 'group_javascript_help';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'javascript';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_javascript_advanced';
  $field_group->data = array(
    'label' => 'Custom Help/Instructions',
    'weight' => '15',
    'children' => array(
      0 => 'field__admin_notes',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Custom Help/Instructions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-javascript-help field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_javascript_help|catalyst|javascript|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stylesheet_advanced|catalyst|stylesheet|form';
  $field_group->group_name = 'group_stylesheet_advanced';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'stylesheet';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_file_content';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '8',
    'children' => array(
      0 => 'field__internal',
      1 => 'field__package',
      2 => 'group_stylesheet_help',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Advanced',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-stylesheet-advanced field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_stylesheet_advanced|catalyst|stylesheet|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stylesheet_help|catalyst|stylesheet|form';
  $field_group->group_name = 'group_stylesheet_help';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'stylesheet';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_stylesheet_advanced';
  $field_group->data = array(
    'label' => 'Custom Help/Instructions',
    'weight' => '13',
    'children' => array(
      0 => 'field__admin_notes',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Custom Help/Instructions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-stylesheet-help field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_stylesheet_help|catalyst|stylesheet|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Advanced');
  t('Custom Help/Instructions');
  t('Media/Files');
  t('Stylesheet content');
  t('Tabs');

  return $field_groups;
}
