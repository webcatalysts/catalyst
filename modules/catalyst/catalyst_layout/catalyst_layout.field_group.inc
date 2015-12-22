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
      0 => 'field_layout_preprocess',
      1 => 'field_layout_page_title_pattern',
      2 => 'field_layout_debug',
      3 => 'field_layout_html_head',
      4 => 'group_layout_form_alter',
      5 => 'group_layout_drupal',
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
      0 => 'field_layout_blocks',
      1 => 'field_catalyst_blocks_add',
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
      0 => 'field_layout_content',
      1 => 'field_layout_doctype',
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
      0 => 'field_layout_includes_css',
      1 => 'field_layout_css',
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
      0 => 'field_layout_drupal_js',
      1 => 'field_drupal_css',
      2 => 'field_layout_show_messages',
      3 => 'field_catalyst_drupal_processing',
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
      0 => 'field_catalyst_custom_files',
      1 => 'field_catalyst_shared_files',
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
      0 => 'field_layout_onselect',
      1 => 'field_layout_ondeselect',
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
      0 => 'field_layout_includes_js',
      1 => 'field_layout_js',
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
      0 => 'field_layout_regions',
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
      0 => 'group_layout_js',
      1 => 'group_layout_css',
      2 => 'group_layout_advanced',
      3 => 'group_layout_content',
      4 => 'group_layout_regions',
      5 => 'group_layout_blocks',
      6 => 'group_layout_files',
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
