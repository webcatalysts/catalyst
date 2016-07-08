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
    'label' => 'Advanced Settings',
    'weight' => '20',
    'children' => array(
      0 => 'field__internal',
      1 => 'field__package',
      2 => 'field__preprocess',
      3 => 'group_doctype_drupal',
      4 => 'group_doctype_help',
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
      1 => 'field__doctype_charset',
      2 => 'field__doctype_content_type',
      3 => 'field__machine',
      4 => 'title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-doctype-content field-group-htab',
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
  $field_group->identifier = 'group_doctype_form_alter|catalyst|doctype|form';
  $field_group->group_name = 'group_doctype_form_alter';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'doctype';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_doctype_advanced';
  $field_group->data = array(
    'label' => 'Form customizations',
    'weight' => '26',
    'children' => array(
      0 => 'field__ondeselect',
      1 => 'field__onselect',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Form customizations',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-doctype-form-alter field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_doctype_form_alter|catalyst|doctype|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_doctype_help|catalyst|doctype|form';
  $field_group->group_name = 'group_doctype_help';
  $field_group->entity_type = 'catalyst';
  $field_group->bundle = 'doctype';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_doctype_advanced';
  $field_group->data = array(
    'label' => 'Custom Help/Instructions',
    'weight' => '27',
    'children' => array(
      0 => 'field__admin_notes',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Custom Help/Instructions',
      'instance_settings' => array(
        'required_fields' => 1,
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
      0 => 'group_doctype_advanced',
      1 => 'group_doctype_content',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-doctype-tabs field-group-htabs',
      ),
    ),
  );
  $field_groups['group_doctype_tabs|catalyst|doctype|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Advanced Settings');
  t('Basics');
  t('Custom Help/Instructions');
  t('Drupal options');
  t('Form customizations');
  t('Tabs');

  return $field_groups;
}
