<?php
/**
 * @file
 * catalyst_block.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function catalyst_block_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_block_advanced|catalyst|block|form';
  $field_group->group_name = 'group_block_advanced';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'block';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_block_tabs';
  $field_group->data = array(
    'label' => 'Advanced Settings',
    'weight' => '9',
    'children' => array(
      0 => 'field_block_preprocess',
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
  $export['group_block_advanced|catalyst|block|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_block_content|catalyst|block|form';
  $field_group->group_name = 'group_block_content';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'block';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_block_tabs';
  $field_group->data = array(
    'label' => 'Block basics',
    'weight' => '4',
    'children' => array(
      0 => 'field_block_content',
      1 => 'field_block_machine',
      2 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-block-content field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_block_content|catalyst|block|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_block_css|catalyst|block|form';
  $field_group->group_name = 'group_block_css';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'block';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_block_tabs';
  $field_group->data = array(
    'label' => 'Cascading Stylesheets',
    'weight' => '5',
    'children' => array(
      0 => 'field_catalyst_includes_css',
      1 => 'field_catalyst_custom_css',
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
  $export['group_block_css|catalyst|block|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_block_files|catalyst|block|form';
  $field_group->group_name = 'group_block_files';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'block';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_block_tabs';
  $field_group->data = array(
    'label' => 'Media/Files',
    'weight' => '7',
    'children' => array(
      0 => 'field_catalyst_custom_files',
      1 => 'field_catalyst_shared_files',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-block-files field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_block_files|catalyst|block|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_block_js|catalyst|block|form';
  $field_group->group_name = 'group_block_js';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'block';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_block_tabs';
  $field_group->data = array(
    'label' => 'Javascripts',
    'weight' => '6',
    'children' => array(
      0 => 'field_catalyst_includes_js',
      1 => 'field_catalyst_custom_js',
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
  $export['group_block_js|catalyst|block|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_block_placement|catalyst|block|form';
  $field_group->group_name = 'group_block_placement';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'block';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_block_tabs';
  $field_group->data = array(
    'label' => 'Block Placement',
    'weight' => '8',
    'children' => array(
      0 => 'field_block_placements',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-block-placement field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $export['group_block_placement|catalyst|block|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_block_tabs|catalyst|block|form';
  $field_group->group_name = 'group_block_tabs';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'block';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_block_advanced',
      1 => 'group_block_css',
      2 => 'group_block_js',
      3 => 'group_block_placement',
      4 => 'group_block_content',
      5 => 'group_block_files',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-block-tabs field-group-htabs',
      ),
    ),
  );
  $export['group_block_tabs|catalyst|block|form'] = $field_group;

  return $export;
}
