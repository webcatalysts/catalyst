<?php
/**
 * @file
 * catalyst_page.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function catalyst_page_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_advanced|catalyst|page|form';
  $field_group->group_name = 'group_page_advanced';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_page_tabs';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '8',
    'children' => array(
      0 => 'field__html_head',
      1 => 'field__internal',
      2 => 'field__package',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_page_advanced|catalyst|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_blocks|catalyst|page|form';
  $field_group->group_name = 'group_page_blocks';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_page_tabs';
  $field_group->data = array(
    'label' => 'Blocks',
    'weight' => '6',
    'children' => array(
      0 => 'field__blockplacements__layfield',
      1 => 'field__blocks_related',
      2 => 'field___block_placements_entity',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_page_blocks|catalyst|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_content|catalyst|page|form';
  $field_group->group_name = 'group_page_content';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_page_tabs';
  $field_group->data = array(
    'label' => 'Page content',
    'weight' => '1',
    'children' => array(
      0 => 'field__body',
      1 => 'field__layout',
      2 => 'field__machine',
      3 => 'field__menu',
      4 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Page content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_page_content|catalyst|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_css|catalyst|page|form';
  $field_group->group_name = 'group_page_css';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_page_tabs';
  $field_group->data = array(
    'label' => 'Stylesheets',
    'weight' => '3',
    'children' => array(
      0 => 'field__css__page',
      1 => 'field__media_stylesheets__page',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Stylesheets',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_page_css|catalyst|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_files|catalyst|page|form';
  $field_group->group_name = 'group_page_files';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_page_tabs';
  $field_group->data = array(
    'label' => 'Files',
    'weight' => '5',
    'children' => array(
      0 => 'field__files',
      1 => 'field__media_files',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_page_files|catalyst|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_help|catalyst|page|form';
  $field_group->group_name = 'group_page_help';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_page_tabs';
  $field_group->data = array(
    'label' => 'Help',
    'weight' => '9',
    'children' => array(
      0 => 'field__admin_notes',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Help',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_page_help|catalyst|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_js|catalyst|page|form';
  $field_group->group_name = 'group_page_js';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_page_tabs';
  $field_group->data = array(
    'label' => 'Javascripts',
    'weight' => '4',
    'children' => array(
      0 => 'field__js__page',
      1 => 'field__media_javascripts__page',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Javascripts',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_page_js|catalyst|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_php|catalyst|page|form';
  $field_group->group_name = 'group_page_php';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_page_tabs';
  $field_group->data = array(
    'label' => 'Processing',
    'weight' => '2',
    'children' => array(
      0 => 'field__access',
      1 => 'field__preprocess',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-page-php field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_page_php|catalyst|page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_page_tabs|catalyst|page|form';
  $field_group->group_name = 'group_page_tabs';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '1',
    'children' => array(
      0 => 'group_page_advanced',
      1 => 'group_page_blocks',
      2 => 'group_page_content',
      3 => 'group_page_css',
      4 => 'group_page_files',
      5 => 'group_page_help',
      6 => 'group_page_js',
      7 => 'group_page_php',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-page-tabs field-group-tabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_page_tabs|catalyst|page|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Advanced');
  t('Blocks');
  t('Files');
  t('Help');
  t('Javascripts');
  t('Page content');
  t('Processing');
  t('Stylesheets');
  t('Tabs');

  return $field_groups;
}
