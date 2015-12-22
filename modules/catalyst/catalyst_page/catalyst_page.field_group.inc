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
  $field_group->parent_name = 'group_cpage_tabs';
  $field_group->data = array(
    'label' => 'Advanced Settings',
    'weight' => '13',
    'children' => array(
      0 => 'field_cpage_head',
      1 => 'field_cpage_preprocess',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_cpage_advanced|node|cpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cpage_blocks|node|cpage|form';
  $field_group->group_name = 'group_cpage_blocks';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cpage_tabs';
  $field_group->data = array(
    'label' => 'Blocks',
    'weight' => '12',
    'children' => array(
      0 => 'field_cpage_blocks',
      1 => 'field_cpage_blocks_add',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_cpage_blocks|node|cpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cpage_content|node|cpage|form';
  $field_group->group_name = 'group_cpage_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cpage_tabs';
  $field_group->data = array(
    'label' => 'Page content',
    'weight' => '8',
    'children' => array(
      0 => 'field_cpage_content',
      1 => 'field_cpage_layout',
      2 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cpage-content field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_cpage_content|node|cpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cpage_css|node|cpage|form';
  $field_group->group_name = 'group_cpage_css';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cpage_tabs';
  $field_group->data = array(
    'label' => 'Cascading Style Sheets',
    'weight' => '9',
    'children' => array(
      0 => 'field_cpage_includes_css',
      1 => 'field_cpage_custom_css',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_cpage_css|node|cpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cpage_files|node|cpage|form';
  $field_group->group_name = 'group_cpage_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cpage_tabs';
  $field_group->data = array(
    'label' => 'Media/Files',
    'weight' => '11',
    'children' => array(
      0 => 'field_catalyst_shared_files',
      1 => 'field_catalyst_custom_files',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cpage-files field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_cpage_files|node|cpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cpage_js|node|cpage|form';
  $field_group->group_name = 'group_cpage_js';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpage';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cpage_tabs';
  $field_group->data = array(
    'label' => 'Javascript',
    'weight' => '10',
    'children' => array(
      0 => 'field_cpage_includes_js',
      1 => 'field_cpage_custom_js',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_cpage_js|node|cpage|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cpage_tabs|node|cpage|form';
  $field_group->group_name = 'group_cpage_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'cpage';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_cpage_js',
      1 => 'group_cpage_css',
      2 => 'group_cpage_advanced',
      3 => 'group_cpage_blocks',
      4 => 'group_cpage_content',
      5 => 'group_cpage_files',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-cpage-tabs field-group-htabs',
      ),
    ),
  );
  $export['group_cpage_tabs|node|cpage|form'] = $field_group;

  return $export;
}
