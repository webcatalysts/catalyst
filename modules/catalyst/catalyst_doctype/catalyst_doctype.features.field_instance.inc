<?php
/**
 * @file
 * catalyst_doctype.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function catalyst_doctype_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'catalyst-doctype-field_doctype_footer'.
  $field_instances['catalyst-doctype-field_doctype_footer'] = array(
    'bundle' => 'doctype',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field_doctype_footer',
    'label' => 'Footer',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'catalyst-doctype-field_doctype_handle'.
  $field_instances['catalyst-doctype-field_doctype_handle'] = array(
    'bundle' => 'doctype',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'safeword',
        'settings' => array(),
        'type' => 'safeword_machine_basic',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field_doctype_handle',
    'label' => 'Handle',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'safeword',
      'settings' => array(),
      'type' => 'safeword_machine_name_only',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'catalyst-doctype-field_doctype_header'.
  $field_instances['catalyst-doctype-field_doctype_header'] = array(
    'bundle' => 'doctype',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field_doctype_header',
    'label' => 'Header',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
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

  // Exported field_instance: 'catalyst-doctype-field_doctype_ondeselect'.
  $field_instances['catalyst-doctype-field_doctype_ondeselect'] = array(
    'bundle' => 'doctype',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Custom javascript that is executed when this doctype is deselected on the layout form.',
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
    'field_name' => 'field_doctype_ondeselect',
    'label' => 'On DeSelect',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'catalyst-doctype-field_doctype_onselect'.
  $field_instances['catalyst-doctype-field_doctype_onselect'] = array(
    'bundle' => 'doctype',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Custom javascript that is called when this doctype is selected on the layout form.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field_doctype_onselect',
    'label' => 'On Select',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 4,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Custom javascript that is called when this doctype is selected on the layout form.');
  t('Custom javascript that is executed when this doctype is deselected on the layout form.');
  t('Footer');
  t('Handle');
  t('Header');
  t('On DeSelect');
  t('On Select');

  return $field_instances;
}
