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

  // Exported field_instance: 'node-cpage-field__blockplacements__layfield'.
  $field_instances['node-cpage-field__blockplacements__layfield'] = array(
    'bundle' => 'cpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field__blockplacements__layfield',
    'label' => 'Blocks',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'catalyst_field_api',
      'settings' => array(),
      'type' => 'block_placement_layout_field_widget',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-cpage-field__blocks_related'.
  $field_instances['node-cpage-field__blocks_related'] = array(
    'bundle' => 'cpage',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field__blocks_related',
    'label' => 'Add Blocks',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'inline_entity_form',
      'settings' => array(
        'fields' => array(),
        'type_settings' => array(
          'allow_existing' => 0,
          'allow_new' => 1,
          'delete_references' => 0,
          'label_plural' => 'blocks',
          'label_singular' => 'block',
          'match_operator' => 'CONTAINS',
          'override_labels' => 1,
        ),
      ),
      'type' => 'inline_entity_form',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-cpage-field__body'.
  $field_instances['node-cpage-field__body'] = array(
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
    'field_name' => 'field__body',
    'label' => 'Content',
    'required' => 1,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'catalyst_html' => 'catalyst_html',
        ),
        'allowed_formats_toggle' => 1,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'catalyst_html' => array(
              'weight' => 0,
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
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-cpage-field__css__page'.
  $field_instances['node-cpage-field__css__page'] = array(
    'bundle' => 'cpage',
    'default_value' => NULL,
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
    'entity_type' => 'node',
    'field_name' => 'field__css__page',
    'label' => 'Custom CSS',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'catalyst_css' => 'catalyst_css',
        ),
        'allowed_formats_toggle' => 1,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'catalyst_css' => array(
              'weight' => 0,
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
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-cpage-field__files'.
  $field_instances['node-cpage-field__files'] = array(
    'bundle' => 'cpage',
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
    'entity_type' => 'node',
    'field_name' => 'field__files',
    'label' => 'Custom Files',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'gif jpg jpeg png svg doc docx rtf txt wpd wps cvs dat pps ppt pptx sdf vcf xml m3u m4a mid mp3 wma wav 3gp avi flv swf mov mp4 mpg wmv',
      'filefield_paths' => array(
        'active_updating' => 0,
        'file_name' => array(
          'options' => array(
            'pathauto' => 1,
            'slashes' => 0,
            'transliterate' => 1,
          ),
          'value' => '[file:ffp-name-only-original].[file:ffp-extension-original]',
        ),
        'file_path' => array(
          'options' => array(
            'pathauto' => 1,
            'slashes' => 0,
            'transliterate' => 1,
          ),
          'value' => 'media/cpage/[node:title]',
        ),
        'redirect' => FALSE,
        'retroactive_update' => 0,
      ),
      'filefield_paths_enabled' => 1,
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'progress_indicator' => 'bar',
      ),
      'type' => 'file_generic',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-cpage-field__html_head'.
  $field_instances['node-cpage-field__html_head'] = array(
    'bundle' => 'cpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Custom markup that will be added the <head> tag of the layout. Allows for metatags, external javascript/stylesheets, etc.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field__html_head',
    'label' => 'Custom Head',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'catalyst_html' => 'catalyst_html',
        ),
        'allowed_formats_toggle' => 1,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'catalyst_html' => array(
              'weight' => 0,
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
        'rows' => 6,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-cpage-field__internal'.
  $field_instances['node-cpage-field__internal'] = array(
    'bundle' => 'cpage',
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
        'weight' => 14,
      ),
    ),
    'entity_type' => 'node',
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-cpage-field__js__page'.
  $field_instances['node-cpage-field__js__page'] = array(
    'bundle' => 'cpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field__js__page',
    'label' => 'Custom Javascript',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'catalyst_js' => 'catalyst_js',
        ),
        'allowed_formats_toggle' => 1,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'catalyst_js' => array(
              'weight' => 0,
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
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'node-cpage-field__layout'.
  $field_instances['node-cpage-field__layout'] = array(
    'bundle' => 'cpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field__layout',
    'label' => 'Layout',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-cpage-field__media_files'.
  $field_instances['node-cpage-field__media_files'] = array(
    'bundle' => 'cpage',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field__media_files',
    'label' => 'Shared Files',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'inline_entity_form',
      'settings' => array(
        'fields' => array(),
        'type_settings' => array(
          'allow_existing' => 1,
          'allow_new' => 1,
          'delete_references' => 0,
          'label_plural' => 'files',
          'label_singular' => 'file',
          'match_operator' => 'CONTAINS',
          'override_labels' => 1,
        ),
      ),
      'type' => 'inline_entity_form',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-cpage-field__media_javascripts__page'.
  $field_instances['node-cpage-field__media_javascripts__page'] = array(
    'bundle' => 'cpage',
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
    'entity_type' => 'node',
    'field_name' => 'field__media_javascripts__page',
    'label' => 'Javascript Includes',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'inline_entity_form',
      'settings' => array(
        'fields' => array(),
        'type_settings' => array(
          'allow_existing' => 1,
          'allow_new' => 1,
          'delete_references' => 0,
          'label_plural' => 'javascripts',
          'label_singular' => 'javascript',
          'match_operator' => 'CONTAINS',
          'override_labels' => 1,
        ),
      ),
      'type' => 'inline_entity_form',
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'node-cpage-field__media_stylesheets__page'.
  $field_instances['node-cpage-field__media_stylesheets__page'] = array(
    'bundle' => 'cpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field__media_stylesheets__page',
    'label' => 'Stylesheet Includes',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'inline_entity_form',
      'settings' => array(
        'fields' => array(),
        'type_settings' => array(
          'allow_existing' => 1,
          'allow_new' => 1,
          'delete_references' => 0,
          'label_plural' => 'stylesheets',
          'label_singular' => 'stylesheet',
          'match_operator' => 'CONTAINS',
          'override_labels' => 1,
        ),
      ),
      'type' => 'inline_entity_form',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-cpage-field__package'.
  $field_instances['node-cpage-field__package'] = array(
    'bundle' => 'cpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field__package',
    'label' => 'Package',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'entityreference_autocreate' => array(
          'active' => 1,
          'author' => '',
          'author_current_user' => 1,
          'status' => -1,
        ),
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete_tags',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-cpage-field__preprocess'.
  $field_instances['node-cpage-field__preprocess'] = array(
    'bundle' => 'cpage',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field__preprocess',
    'label' => 'Preprocessing',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'catalyst_php' => 'catalyst_php',
        ),
        'allowed_formats_toggle' => 1,
        'default_order_toggle' => 0,
        'default_order_wrapper' => array(
          'formats' => array(
            'catalyst_php' => array(
              'weight' => 0,
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
      'weight' => 3,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add Blocks');
  t('Blocks');
  t('Content');
  t('Custom CSS');
  t('Custom Files');
  t('Custom Head');
  t('Custom Javascript');
  t('Custom markup that will be added the <head> tag of the layout. Allows for metatags, external javascript/stylesheets, etc.');
  t('Internal');
  t('Javascript Includes');
  t('Layout');
  t('Package');
  t('Preprocessing');
  t('Shared Files');
  t('Stylesheet Includes');

  return $field_instances;
}
