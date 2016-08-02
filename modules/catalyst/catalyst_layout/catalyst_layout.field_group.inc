<?php
/**
 * @file
 * catalyst_layout.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function catalyst_layout_field_group_info() {
  $field_groups = array();

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
    'weight' => '10',
    'children' => array(
      0 => 'field__debug',
      1 => 'field__html_head',
      2 => 'field__internal',
      3 => 'field__layout_page_title_pattern',
      4 => 'field__package',
      5 => 'group_layout_drupal',
      6 => 'group_layout_help',
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
  $field_groups['group_layout_advanced|catalyst|layout|form'] = $field_group;

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
    'weight' => '9',
    'children' => array(
      0 => 'field__blockplacements__layout',
      1 => 'field__blocks_related',
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
  $field_groups['group_layout_blocks|catalyst|layout|form'] = $field_group;

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
      2 => 'field__machine',
      3 => 'title',
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
  $field_groups['group_layout_content|catalyst|layout|form'] = $field_group;

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
    'weight' => '5',
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
  $field_groups['group_layout_css|catalyst|layout|form'] = $field_group;

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
      1 => 'field__layout_drupal_css',
      2 => 'field__layout_drupal_js',
      3 => 'field__layout_show_messages',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Drupal options',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-layout-drupal field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_layout_drupal|catalyst|layout|form'] = $field_group;

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
        'classes' => 'group-layout-files field-group-htab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_layout_files|catalyst|layout|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_help|catalyst|layout|form';
  $field_group->group_name = 'group_layout_help';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'layout';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_layout_advanced';
  $field_group->data = array(
    'label' => 'Custom Help/Instructions',
    'weight' => '7',
    'children' => array(
      0 => 'field__admin_notes',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Custom Help/Instructions',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-layout-help field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_layout_help|catalyst|layout|form'] = $field_group;

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
    'weight' => '6',
    'children' => array(
      0 => 'field__js__layout',
      1 => 'field__media_javascripts__layout',
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
  $field_groups['group_layout_js|catalyst|layout|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_layout_php|catalyst|layout|form';
  $field_group->group_name = 'group_layout_php';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'layout';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_layout_tabs';
  $field_group->data = array(
    'label' => 'Processing',
    'weight' => '4',
    'children' => array(
      0 => 'field__preprocess',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-layout-php field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_layout_php|catalyst|layout|form'] = $field_group;

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
    'weight' => '8',
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
  $field_groups['group_layout_regions|catalyst|layout|form'] = $field_group;

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
      7 => 'group_layout_php',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-layout-tabs field-group-htabs',
      ),
    ),
  );
  $field_groups['group_layout_tabs|catalyst|layout|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Advanced');
  t('Blocks');
  t('Custom Help/Instructions');
  t('Drupal options');
  t('Javascript');
  t('Layout Basics');
  t('Media/Files');
  t('Page form customizations');
  t('Processing');
  t('Regions');
  t('Stylesheets');
  t('Tabs');

  return $field_groups;
}
