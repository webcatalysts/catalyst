<?php
/**
 * @file
 * catalyst_block.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function catalyst_block_field_group_info() {
  $field_groups = array();

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
      0 => 'field__internal',
      1 => 'field__package',
      2 => 'field__preprocess',
      3 => 'group_block_help',
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
  $field_groups['group_block_advanced|catalyst|block|form'] = $field_group;

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
      0 => 'field__body',
      1 => 'field__machine',
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
  $field_groups['group_block_content|catalyst|block|form'] = $field_group;

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
      0 => 'field__css',
      1 => 'field__media_stylesheets',
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
  $field_groups['group_block_css|catalyst|block|form'] = $field_group;

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
      0 => 'field__files',
      1 => 'field__media_files',
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
  $field_groups['group_block_files|catalyst|block|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_block_help|catalyst|block|form';
  $field_group->group_name = 'group_block_help';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'block';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_block_advanced';
  $field_group->data = array(
    'label' => 'Custom Help/Instructions',
    'weight' => '5',
    'children' => array(
      0 => 'field__admin_notes',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Custom Help/Instructions',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-block-help field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_block_help|catalyst|block|form'] = $field_group;

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
      0 => 'field__js',
      1 => 'field__media_javascripts',
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
  $field_groups['group_block_js|catalyst|block|form'] = $field_group;

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
      0 => 'field__blockplacements__block',
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
  $field_groups['group_block_placement|catalyst|block|form'] = $field_group;

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
      1 => 'group_block_content',
      2 => 'group_block_css',
      3 => 'group_block_files',
      4 => 'group_block_js',
      5 => 'group_block_placement',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-block-tabs field-group-htabs',
      ),
    ),
  );
  $field_groups['group_block_tabs|catalyst|block|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Advanced Settings');
  t('Block Placement');
  t('Block basics');
  t('Cascading Stylesheets');
  t('Custom Help/Instructions');
  t('Javascripts');
  t('Media/Files');
  t('Tabs');

  return $field_groups;
}
