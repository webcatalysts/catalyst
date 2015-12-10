<?php
/**
 * @file
 * catalyst_page.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function catalyst_page_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cpage_advanced|node|cpage|form';
  $field_group->group_name = 'group_cpage_advanced';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced Settings',
    'weight' => '5',
    'children' => array(
      0 => 'field_cpage_head',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Advanced Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-cpage-advanced field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_cpage_advanced|node|cpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cpage_css|node|cpage|form';
  $field_group->group_name = 'group_cpage_css';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Cascading Style Sheets',
    'weight' => '3',
    'children' => array(
      0 => 'field_cpage_css',
      1 => 'field_cpage_includes_css',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Cascading Style Sheets',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-cpage-css field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_cpage_css|node|cpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cpage_js|node|cpage|form';
  $field_group->group_name = 'group_cpage_js';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Javascript',
    'weight' => '4',
    'children' => array(
      0 => 'field_custom_js',
      1 => 'field_cpage_includes_js',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Javascript',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-cpage-js field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_cpage_js|node|cpage|form'] = $field_group;

  return $export;
}
