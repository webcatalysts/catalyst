<?php
/**
 * @file
 * catalyst_layout.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function catalyst_layout_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_css|catalyst|layout|form';
  $field_group->group_name = 'group_layout_css';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'layout';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Cascading Style Sheets',
    'weight' => '4',
    'children' => array(
      0 => 'field_layout_includes_css',
      1 => 'field_layout_css',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Cascading Style Sheets',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-layout-css field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_layout_css|catalyst|layout|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_js|catalyst|layout|form';
  $field_group->group_name = 'group_layout_js';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'layout';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Javascript',
    'weight' => '6',
    'children' => array(
      0 => 'field_layout_includes_js',
      1 => 'field_layout_js',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Javascript',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-layout-js field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_layout_js|catalyst|layout|form'] = $field_group;

  return $export;
}
