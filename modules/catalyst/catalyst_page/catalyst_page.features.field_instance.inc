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

  // Exported field_instance: 'node-cpage-field_catalyst_custom_files'.
  $field_instances['node-cpage-field_catalyst_custom_files'] = array(
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
    'field_name' => 'field_catalyst_custom_files',
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

  // Exported field_instance: 'node-cpage-field_catalyst_shared_files'.
  $field_instances['node-cpage-field_catalyst_shared_files'] = array(
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
    'field_name' => 'field_catalyst_shared_files',
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

  // Exported field_instance: 'node-cpage-field_cpage_blocks'.
  $field_instances['node-cpage-field_cpage_blocks'] = array(
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
    'field_name' => 'field_cpage_blocks',
    'label' => 'Blocks',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'catalyst_block',
      'settings' => array(),
      'type' => 'block_placement_layout_field_widget',
      'weight' => 3,
    ),
  );

  // Exported field_instance: 'node-cpage-field_cpage_blocks_add'.
  $field_instances['node-cpage-field_cpage_blocks_add'] = array(
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
    'field_name' => 'field_cpage_blocks_add',
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
          'cpage_html' => 'cpage_html',
          'css' => 0,
          'full_html' => 0,
          'html_simple' => 0,
          'js' => 0,
          'layout_html' => 0,
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
        'rows' => 20,
      ),
      'type' => 'text_textarea',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-cpage-field_cpage_custom_css'.
  $field_instances['node-cpage-field_cpage_custom_css'] = array(
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
    'field_name' => 'field_cpage_custom_css',
    'label' => 'Custom CSS',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'cpage_html' => 0,
          'css' => 'css',
          'full_html' => 0,
          'html_simple' => 0,
          'js' => 0,
          'layout_html' => 0,
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
        'rows' => 10,
      ),
      'type' => 'text_textarea',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-cpage-field_cpage_custom_js'.
  $field_instances['node-cpage-field_cpage_custom_js'] = array(
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
    'field_name' => 'field_cpage_custom_js',
    'label' => 'Custom Javascript',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'cpage_html' => 0,
          'css' => 0,
          'full_html' => 0,
          'html_simple' => 0,
          'js' => 'js',
          'layout_html' => 0,
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
        'rows' => 10,
      ),
      'type' => 'text_textarea',
      'weight' => 16,
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
        'weight' => 3,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_cpage_head',
    'label' => 'Custom Head',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'cpage_html' => 'cpage_html',
          'css' => 0,
          'full_html' => 0,
          'html_simple' => 0,
          'js' => 0,
          'layout_html' => 0,
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
        'rows' => 6,
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
        'weight' => 7,
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
        'weight' => 6,
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

  // Exported field_instance: 'node-cpage-field_cpage_layout'.
  $field_instances['node-cpage-field_cpage_layout'] = array(
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
    'field_name' => 'field_cpage_layout',
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

  // Exported field_instance: 'node-cpage-field_cpage_preprocess'.
  $field_instances['node-cpage-field_cpage_preprocess'] = array(
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
    'field_name' => 'field_cpage_preprocess',
    'label' => 'Preprocessing',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'cpage_html' => 0,
          'css' => 0,
          'html_simple' => 0,
          'js' => 0,
          'layout_html' => 0,
          'php' => 'php',
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
  t('Javascript Includes');
  t('Layout');
  t('Preprocessing');
  t('Shared Files');
  t('Stylesheet Includes');

  return $field_instances;
}
