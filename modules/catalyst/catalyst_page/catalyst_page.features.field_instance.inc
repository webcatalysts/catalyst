<?php
/**
 * @file
 * catalyst_page.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function catalyst_page_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-cpage-field_cpage_content'.
  $field_instances['node-cpage-field_cpage_content'] = array(
    'bundle' => 'cpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cpage_content',
    'label' => 'Content',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'ace_editor' => 0,
          'cpage_html' => 'cpage_html',
          'layout_html' => 0,
          'plain_text' => 0,
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'ace_editor' => array(
              'weight' => -50,
            ),
            'cpage_html' => array(
              'weight' => 0,
            ),
            'layout_html' => array(
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
        'rows' => 10,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'node-cpage-field_cpage_css'.
  $field_instances['node-cpage-field_cpage_css'] = array(
    'bundle' => 'cpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Custom CSS specific to this page.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cpage_css',
    'label' => 'Custom CSS',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'cpage_html' => 0,
          'layout_html' => 0,
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'cpage_html' => array(
              'weight' => 0,
            ),
            'layout_html' => array(
              'weight' => 0,
            ),
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
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

  // Exported field_instance: 'node-cpage-field_cpage_head'.
  $field_instances['node-cpage-field_cpage_head'] = array(
    'bundle' => 'cpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Custom markup that will be added the <head> tag of the layout. Allows for metatags, external javascript/stylesheets, etc.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cpage_head',
    'label' => 'Custom Head',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
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

  // Exported field_instance: 'node-cpage-field_cpage_includes_css'.
  $field_instances['node-cpage-field_cpage_includes_css'] = array(
    'bundle' => 'cpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cpage_includes_css',
    'label' => 'Stylesheet Includes',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-cpage-field_cpage_includes_js'.
  $field_instances['node-cpage-field_cpage_includes_js'] = array(
    'bundle' => 'cpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cpage_includes_js',
    'label' => 'Javascript Includes',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-cpage-field_custom_js'.
  $field_instances['node-cpage-field_custom_js'] = array(
    'bundle' => 'cpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Custom javascript specific to this page.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_custom_js',
    'label' => 'Custom Javascript',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'plain_text' => array(
              'weight' => 10,
            ),
          ),
        ),
      ),
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
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Content');
  t('Custom CSS');
  t('Custom CSS specific to this page.');
  t('Custom Head');
  t('Custom Javascript');
  t('Custom javascript specific to this page.');
  t('Custom markup that will be added the <head> tag of the layout. Allows for metatags, external javascript/stylesheets, etc.');
  t('Javascript Includes');
  t('Stylesheet Includes');

  return $field_instances;
}
