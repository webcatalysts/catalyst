<?php
/**
 * @file
 * catalyst_template.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function catalyst_template_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_template_advanced|catalyst|template|form';
  $field_group->group_name = 'group_template_advanced';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'template';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_template_tabs';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '16',
    'children' => array(
      0 => 'field__html_head',
      1 => 'field__preprocess',
      2 => 'field__debug',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-template-advanced field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_template_advanced|catalyst|template|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_template_blocks|catalyst|template|form';
  $field_group->group_name = 'group_template_blocks';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'template';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_template_tabs';
  $field_group->data = array(
    'label' => 'Blocks',
    'weight' => '15',
    'children' => array(
      0 => 'field__blockplacements__layfield',
      1 => 'field__blocks_related',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-template-blocks field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_template_blocks|catalyst|template|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_template_css|catalyst|template|form';
  $field_group->group_name = 'group_template_css';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'template';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_template_tabs';
  $field_group->data = array(
    'label' => 'Stylesheets',
    'weight' => '12',
    'children' => array(
      0 => 'field__media_stylesheets',
      1 => 'field__css',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-template-css field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_template_css|catalyst|template|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_template_files|catalyst|template|form';
  $field_group->group_name = 'group_template_files';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'template';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_template_tabs';
  $field_group->data = array(
    'label' => 'Media/Files',
    'weight' => '14',
    'children' => array(
      0 => 'field__files',
      1 => 'field__media_files',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-template-files field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_template_files|catalyst|template|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_template_js|catalyst|template|form';
  $field_group->group_name = 'group_template_js';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'template';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_template_tabs';
  $field_group->data = array(
    'label' => 'Javascript',
    'weight' => '13',
    'children' => array(
      0 => 'field__media_javascripts',
      1 => 'field__js',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-template-js field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_template_js|catalyst|template|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_template_tabs|catalyst|template|form';
  $field_group->group_name = 'group_template_tabs';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'template';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '4',
    'children' => array(
      0 => 'group_template_js',
      1 => 'group_template_css',
      2 => 'group_template_blocks',
      3 => 'group_template_advanced',
      4 => 'group_template_files',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-template-tabs field-group-htabs',
      ),
    ),
  );
  $export['group_template_tabs|catalyst|template|form'] = $field_group;

  return $export;
}
