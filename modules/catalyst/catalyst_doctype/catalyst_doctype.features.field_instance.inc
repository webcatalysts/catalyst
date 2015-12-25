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

  // Exported field_instance:
  // 'catalyst-doctype-field_catalyst_drupal_processing'.
  $field_instances['catalyst-doctype-field_catalyst_drupal_processing'] = array(
    'bundle' => 'doctype',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field_catalyst_drupal_processing',
    'label' => 'Enable Drupal processing',
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
      'weight' => 23,
    ),
  );

  // Exported field_instance: 'catalyst-doctype-field_doctype_charset'.
  $field_instances['catalyst-doctype-field_doctype_charset'] = array(
    'bundle' => 'doctype',
    'default_value' => array(
      0 => array(
        'value' => 'utf-8',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field_doctype_charset',
    'label' => 'Character Set',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'cpage_html' => 'cpage_html',
          'css' => 'css',
          'full_html' => 'full_html',
          'html_simple' => 'html_simple',
          'js' => 'js',
          'layout_html' => 'layout_html',
          'php' => 'php',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'cpage_html' => array(
              'weight' => 0,
            ),
            'css' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => 0,
            ),
            'html_simple' => array(
              'weight' => 0,
            ),
            'js' => array(
              'weight' => -8,
            ),
            'layout_html' => array(
              'weight' => 0,
            ),
            'php' => array(
              'weight' => -5,
            ),
            'php_code' => array(
              'weight' => 11,
            ),
            'plain_text' => array(
              'weight' => -10,
            ),
          ),
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'select_or_other',
      'settings' => array(
        'available_options' => 'utf-8
',
        'available_options_php' => '',
        'markup_available_options_php' => '&lt;none&gt;',
        'other' => 'Other',
        'other_size' => 30,
        'other_title' => '',
        'other_unknown_defaults' => 'other',
        'sort_options' => 0,
      ),
      'type' => 'select_or_other',
      'weight' => 20,
    ),
  );

  // Exported field_instance: 'catalyst-doctype-field_doctype_content'.
  $field_instances['catalyst-doctype-field_doctype_content'] = array(
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
        'weight' => 7,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field_doctype_content',
    'label' => 'Content',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'cpage_html' => 0,
          'css' => 0,
          'full_html' => 0,
          'html_simple' => 0,
          'js' => 0,
          'layout_html' => 'layout_html',
          'php' => 0,
          'php_code' => 0,
          'plain_text' => 0,
        ),
        'allowed_formats_toggle' => 1,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'cpage_html' => array(
              'weight' => -7,
            ),
            'css' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => 0,
            ),
            'html_simple' => array(
              'weight' => 0,
            ),
            'js' => array(
              'weight' => -8,
            ),
            'layout_html' => array(
              'weight' => -6,
            ),
            'php' => array(
              'weight' => -5,
            ),
            'php_code' => array(
              'weight' => 11,
            ),
            'plain_text' => array(
              'weight' => -10,
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
        'rows' => 20,
      ),
      'type' => 'text_textarea',
      'weight' => 18,
    ),
  );

  // Exported field_instance: 'catalyst-doctype-field_doctype_content_type'.
  $field_instances['catalyst-doctype-field_doctype_content_type'] = array(
    'bundle' => 'doctype',
    'default_value' => array(
      0 => array(
        'value' => 'text/html',
      ),
    ),
    'deleted' => 0,
    'description' => '<p><em>For a complete list of content types goto <a href="http://www.freeformatter.com/mime-types-list.html" target="_blank">http://www.freeformatter.com/mime-types-list.html</a>.</em></p>',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field_doctype_content_type',
    'label' => 'HTTP Content-Type',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'cpage_html' => 'cpage_html',
          'css' => 'css',
          'full_html' => 'full_html',
          'html_simple' => 'html_simple',
          'js' => 'js',
          'layout_html' => 'layout_html',
          'php' => 'php',
          'php_code' => 'php_code',
          'plain_text' => 'plain_text',
        ),
        'allowed_formats_toggle' => 0,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'cpage_html' => array(
              'weight' => 0,
            ),
            'css' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => 0,
            ),
            'html_simple' => array(
              'weight' => 0,
            ),
            'js' => array(
              'weight' => -8,
            ),
            'layout_html' => array(
              'weight' => 0,
            ),
            'php' => array(
              'weight' => -5,
            ),
            'php_code' => array(
              'weight' => 11,
            ),
            'plain_text' => array(
              'weight' => -10,
            ),
          ),
        ),
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'select_or_other',
      'settings' => array(
        'available_options' => 'application/json|application/json
application/xml|application/xml
application/xhtml+xml|application/xhtml+xml
text/html|text/html',
        'available_options_php' => '',
        'markup_available_options_php' => '&lt;none&gt;',
        'other' => 'Other',
        'other_size' => 60,
        'other_title' => '',
        'other_unknown_defaults' => 'other',
        'sort_options' => 0,
      ),
      'type' => 'select_or_other',
      'weight' => 19,
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
        'settings' => array(),
        'type' => 'hidden',
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
      'weight' => 28,
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
        'settings' => array(),
        'type' => 'hidden',
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
      'weight' => 27,
    ),
  );

  // Exported field_instance: 'catalyst-doctype-field_doctype_preprocess'.
  $field_instances['catalyst-doctype-field_doctype_preprocess'] = array(
    'bundle' => 'doctype',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field_doctype_preprocess',
    'label' => 'Preprocessing',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'cpage_html' => 0,
          'css' => 0,
          'full_html' => 0,
          'html_simple' => 0,
          'js' => 0,
          'layout_html' => 'layout_html',
          'php' => 0,
          'php_code' => 0,
          'plain_text' => 0,
        ),
        'allowed_formats_toggle' => 1,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'cpage_html' => array(
              'weight' => 0,
            ),
            'css' => array(
              'weight' => -9,
            ),
            'full_html' => array(
              'weight' => 0,
            ),
            'html_simple' => array(
              'weight' => 0,
            ),
            'js' => array(
              'weight' => -8,
            ),
            'layout_html' => array(
              'weight' => 0,
            ),
            'php' => array(
              'weight' => -5,
            ),
            'php_code' => array(
              'weight' => 11,
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
      'weight' => 24,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('<p><em>For a complete list of content types goto <a href="http://www.freeformatter.com/mime-types-list.html" target="_blank">http://www.freeformatter.com/mime-types-list.html</a>.</em></p>');
  t('Character Set');
  t('Content');
  t('Custom javascript that is called when this doctype is selected on the layout form.');
  t('Custom javascript that is executed when this doctype is deselected on the layout form.');
  t('Enable Drupal processing');
  t('HTTP Content-Type');
  t('On DeSelect');
  t('On Select');
  t('Preprocessing');

  return $field_instances;
}
