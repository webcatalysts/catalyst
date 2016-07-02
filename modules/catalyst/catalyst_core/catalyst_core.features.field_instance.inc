<?php
/**
 * @file
 * catalyst_core.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function catalyst_core_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'catalyst-package-field__admin_notes'.
  $field_instances['catalyst-package-field__admin_notes'] = array(
    'bundle' => 'package',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field__admin_notes',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'catalyst_css' => 0,
          'catalyst_doc' => 'catalyst_doc',
          'catalyst_html' => 0,
          'catalyst_js' => 0,
          'catalyst_php' => 0,
          'plain_text' => 0,
        ),
        'allowed_formats_toggle' => 1,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'catalyst_css' => array(
              'weight' => 0,
            ),
            'catalyst_doc' => array(
              'weight' => 0,
            ),
            'catalyst_html' => array(
              'weight' => 0,
            ),
            'catalyst_js' => array(
              'weight' => 0,
            ),
            'catalyst_php' => array(
              'weight' => 0,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'catalyst-package-field__internal'.
  $field_instances['catalyst-package-field__internal'] = array(
    'bundle' => 'package',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'template' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field__internal',
    'label' => 'Internal',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'catalyst-package-field__machine'.
  $field_instances['catalyst-package-field__machine'] = array(
    'bundle' => 'package',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'inline',
        'module' => 'machine',
        'settings' => array(),
        'type' => 'machine_default',
        'weight' => 1,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'template' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field__machine',
    'label' => 'Machine name',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'machine',
      'settings' => array(
        'editable' => FALSE,
        'field_size' => 60,
        'machine_field_label' => 'Machine name',
        'machine_replace_pattern' => '[^a-z0-9_]+',
        'machine_replace_with' => '_',
      ),
      'type' => 'machine_from_title_widget',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Description');
  t('Internal');
  t('Machine name');

  return $field_instances;
}
