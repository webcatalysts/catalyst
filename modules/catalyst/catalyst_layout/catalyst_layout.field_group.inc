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
  $field_group->identifier = 'group_layout_advanced|catalyst|layout|form';
  $field_group->group_name = 'group_layout_advanced';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'layout';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_layout_tabs';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '9',
    'children' => array(
      0 => 'field__debug',
      1 => 'field__html_head',
      2 => 'field__layout_page_title_pattern',
      3 => 'field__preprocess',
      4 => 'group_layout_drupal',
      5 => 'group_layout_form_alter',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Advanced',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-layout-advanced',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_layout_advanced|catalyst|layout|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_blocks|catalyst|layout|form';
  $field_group->group_name = 'group_layout_blocks';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'layout';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_layout_tabs';
  $field_group->data = array(
    'label' => 'Blocks',
    'weight' => '8',
    'children' => array(
      0 => 'field__blocks_related',
      1 => 'field__blockplacements__layout',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-layout-blocks field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_layout_blocks|catalyst|layout|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_content|catalyst|layout|form';
  $field_group->group_name = 'group_layout_content';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'layout';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_layout_tabs';
  $field_group->data = array(
    'label' => 'Layout Basics',
    'weight' => '3',
    'children' => array(
      0 => 'field__body',
      1 => 'field__doctype',
      2 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Layout Basics',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-layout-basic',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_layout_content|catalyst|layout|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_css|catalyst|layout|form';
  $field_group->group_name = 'group_layout_css';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'layout';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_layout_tabs';
  $field_group->data = array(
    'label' => 'Stylesheets',
    'weight' => '4',
    'children' => array(
      0 => 'field__css__layout',
      1 => 'field__media_stylesheets__layout',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Stylesheets',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-layout-css',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_layout_css|catalyst|layout|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_drupal|catalyst|layout|form';
  $field_group->group_name = 'group_layout_drupal';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'layout';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_layout_advanced';
  $field_group->data = array(
    'label' => 'Drupal options',
    'weight' => '6',
    'children' => array(
      0 => 'field__drupal_processing',
      1 => 'field__layout_show_messages',
      2 => 'field__layout_drupal_js',
      3 => 'field__layout_drupal_css',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-layout-drupal field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_layout_drupal|catalyst|layout|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_files|catalyst|layout|form';
  $field_group->group_name = 'group_layout_files';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'layout';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_layout_tabs';
  $field_group->data = array(
    'label' => 'Media/Files',
    'weight' => '6',
    'children' => array(
      0 => 'field__files',
      1 => 'field__media_files',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-layout-files field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_layout_files|catalyst|layout|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_form_alter|catalyst|layout|form';
  $field_group->group_name = 'group_layout_form_alter';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'layout';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_layout_advanced';
  $field_group->data = array(
    'label' => 'Page form customizations',
    'weight' => '7',
    'children' => array(
      0 => 'field__ondeselect',
      1 => 'field__onselect',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Page form customizations',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-layout-form-alter field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $export['group_layout_form_alter|catalyst|layout|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_js|catalyst|layout|form';
  $field_group->group_name = 'group_layout_js';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'layout';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_layout_tabs';
  $field_group->data = array(
    'label' => 'Javascript',
    'weight' => '5',
    'children' => array(
      0 => 'field__media_javascripts__layout',
      1 => 'field__js__layout',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Javascript',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-layout-js',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_layout_js|catalyst|layout|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_regions|catalyst|layout|form';
  $field_group->group_name = 'group_layout_regions';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'layout';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_layout_tabs';
  $field_group->data = array(
    'label' => 'Regions',
    'weight' => '7',
    'children' => array(
      0 => 'field__layout_regions',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-layout-regions field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_layout_regions|catalyst|layout|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_tabs|catalyst|layout|form';
  $field_group->group_name = 'group_layout_tabs';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'layout';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '3',
    'children' => array(
      0 => 'group_layout_advanced',
      1 => 'group_layout_blocks',
      2 => 'group_layout_content',
      3 => 'group_layout_css',
      4 => 'group_layout_files',
      5 => 'group_layout_js',
      6 => 'group_layout_regions',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-layout-tabs field-group-htabs',
      ),
    ),
  );
  $export['group_layout_tabs|catalyst|layout|form'] = $field_group;

  return $export;
}
