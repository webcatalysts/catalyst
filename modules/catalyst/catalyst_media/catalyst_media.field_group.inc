<?php
/**
 * @file
 * catalyst_media.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function catalyst_media_field_group_info() {
  $export = array();

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
      3 => 'field__media_type',
      4 => 'field__media_stylesheet_media',
      5 => 'title',
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
  $export['group_file_content|catalyst|stylesheet|form'] = $field_group;

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
  $export['group_file_files|catalyst|stylesheet|form'] = $field_group;

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
  $export['group_file_tabs|catalyst|stylesheet|form'] = $field_group;

  return $export;
}
