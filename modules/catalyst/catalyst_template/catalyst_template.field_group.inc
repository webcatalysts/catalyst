<?php
/**
 * @file
 * catalyst_template.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function catalyst_template_field_group_info() {
  $field_groups = array();

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
    'weight' => '13',
    'children' => array(
      0 => 'field__debug',
      1 => 'field__html_head',
      2 => 'field__internal',
      3 => 'field__package',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-template-advanced field-group-tab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_template_advanced|catalyst|template|form'] = $field_group;

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
    'weight' => '12',
    'children' => array(
      0 => 'field__blockplacements__layfield',
      1 => 'field__blocks_related',
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
  $field_groups['group_template_blocks|catalyst|template|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_template_content|catalyst|template|form';
  $field_group->group_name = 'group_template_content';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'template';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_template_tabs';
  $field_group->data = array(
    'label' => 'Template',
    'weight' => '7',
    'children' => array(
      0 => 'field__body',
      1 => 'field__layout',
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
  $field_groups['group_template_content|catalyst|template|form'] = $field_group;

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
    'weight' => '9',
    'children' => array(
      0 => 'field__css__page',
      1 => 'field__media_stylesheets__page',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-template-css field-group-tab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_template_css|catalyst|template|form'] = $field_group;

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
    'weight' => '11',
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
  $field_groups['group_template_files|catalyst|template|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_template_help|catalyst|template|form';
  $field_group->group_name = 'group_template_help';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'template';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_template_tabs';
  $field_group->data = array(
    'label' => 'Help',
    'weight' => '14',
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
  $field_groups['group_template_help|catalyst|template|form'] = $field_group;

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
    'weight' => '10',
    'children' => array(
      0 => 'field__js__page',
      1 => 'field__media_javascripts__page',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-template-js field-group-tab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_template_js|catalyst|template|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_template_php|catalyst|template|form';
  $field_group->group_name = 'group_template_php';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'template';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_template_tabs';
  $field_group->data = array(
    'label' => 'Processing',
    'weight' => '8',
    'children' => array(
      0 => 'field__preprocess',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-template-php field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_template_php|catalyst|template|form'] = $field_group;

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
      0 => 'group_template_advanced',
      1 => 'group_template_blocks',
      2 => 'group_template_content',
      3 => 'group_template_css',
      4 => 'group_template_files',
      5 => 'group_template_help',
      6 => 'group_template_js',
      7 => 'group_template_php',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-template-tabs field-group-tabs',
      ),
    ),
  );
  $field_groups['group_template_tabs|catalyst|template|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Advanced');
  t('Blocks');
  t('Help');
  t('Javascript');
  t('Media/Files');
  t('Processing');
  t('Stylesheets');
  t('Tabs');
  t('Template');

  return $field_groups;
}
