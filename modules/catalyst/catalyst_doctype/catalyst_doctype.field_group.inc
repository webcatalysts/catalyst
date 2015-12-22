<?php
/**
 * @file
 * catalyst_doctype.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function catalyst_doctype_field_group_info() {
  $export = array();

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
      0 => 'field_doctype_preprocess',
      1 => 'group_doctype_drupal',
      2 => 'group_doctype_form_alter',
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
  $export['group_doctype_advanced|catalyst|doctype|form'] = $field_group;

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
      0 => 'field_doctype_content',
      1 => 'field_doctype_machine',
      2 => 'field_doctype_content_type',
      3 => 'title',
      4 => 'field_doctype_charset',
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
  $export['group_doctype_content|catalyst|doctype|form'] = $field_group;

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
      0 => 'field_catalyst_drupal_processing',
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
  $export['group_doctype_drupal|catalyst|doctype|form'] = $field_group;

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
      0 => 'field_doctype_onselect',
      1 => 'field_doctype_ondeselect',
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
  $export['group_doctype_form_alter|catalyst|doctype|form'] = $field_group;

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
  $export['group_doctype_tabs|catalyst|doctype|form'] = $field_group;

  return $export;
}
