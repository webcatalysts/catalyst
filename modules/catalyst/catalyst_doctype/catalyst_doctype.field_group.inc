<?php
/**
 * @file
 * catalyst_doctype.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function catalyst_doctype_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_doctype_advanced|catalyst|doctype|form';
  $field_group->group_name = 'group_doctype_advanced';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'doctype';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_doctype_tabs';
  $field_group->data = array(
    'label' => 'Advanced',
    'weight' => '17',
    'children' => array(
      0 => 'field__doctype_charset',
      1 => 'field__doctype_content_type',
      2 => 'field__internal',
      3 => 'field__package',
      4 => 'group_doctype_drupal',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Advanced',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_doctype_advanced|catalyst|doctype|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_doctype_content|catalyst|doctype|form';
  $field_group->group_name = 'group_doctype_content';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'doctype';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_doctype_tabs';
  $field_group->data = array(
    'label' => 'Basics',
    'weight' => '15',
    'children' => array(
      0 => 'field__body',
      1 => 'field__machine',
      2 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-doctype-content field-group-tab',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_doctype_content|catalyst|doctype|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_doctype_drupal|catalyst|doctype|form';
  $field_group->group_name = 'group_doctype_drupal';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'doctype';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_doctype_advanced';
  $field_group->data = array(
    'label' => 'Drupal options',
    'weight' => '25',
    'children' => array(
      0 => 'field__drupal_processing',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Drupal options',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-doctype-drupal field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_doctype_drupal|catalyst|doctype|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_doctype_help|catalyst|doctype|form';
  $field_group->group_name = 'group_doctype_help';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'doctype';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_doctype_tabs';
  $field_group->data = array(
    'label' => 'Help',
    'weight' => '18',
    'children' => array(
      0 => 'field__admin_notes',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Help',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-doctype-help field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_doctype_help|catalyst|doctype|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_doctype_processing|catalyst|doctype|form';
  $field_group->group_name = 'group_doctype_processing';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'doctype';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_doctype_tabs';
  $field_group->data = array(
    'label' => 'Processing',
    'weight' => '16',
    'children' => array(
      0 => 'field__preprocess',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-doctype-processing field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_doctype_processing|catalyst|doctype|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_doctype_tabs|catalyst|doctype|form';
  $field_group->group_name = 'group_doctype_tabs';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'doctype';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tabs',
    'weight' => '0',
    'children' => array(
      0 => 'group_doctype_processing',
      1 => 'group_doctype_advanced',
      2 => 'group_doctype_content',
      3 => 'group_doctype_help',
    ),
    'format_type' => 'tabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-doctype-tabs field-group-tabs',
      ),
    ),
  );
  $field_groups['group_doctype_tabs|catalyst|doctype|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Advanced');
  t('Basics');
  t('Drupal options');
  t('Help');
  t('Processing');
  t('Tabs');

  return $field_groups;
}
