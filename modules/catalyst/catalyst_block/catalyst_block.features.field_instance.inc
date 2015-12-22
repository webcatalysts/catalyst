<?php
/**
 * @file
 * catalyst_block.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function catalyst_block_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'catalyst-block-field_block_content'.
  $field_instances['catalyst-block-field_block_content'] = array(
    'bundle' => 'block',
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
    'entity_type' => 'catalyst',
    'field_name' => 'field_block_content',
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

  // Exported field_instance: 'catalyst-block-field_block_machine'.
  $field_instances['catalyst-block-field_block_machine'] = array(
    'bundle' => 'block',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field_block_machine',
    'label' => 'Machine name',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'machine',
      'settings' => array(
        'machine_size' => 128,
      ),
      'type' => 'machine_from_title_widget',
      'weight' => 1,
    ),
  );

  // Exported field_instance: 'catalyst-block-field_block_placements'.
  $field_instances['catalyst-block-field_block_placements'] = array(
    'bundle' => 'block',
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
    'entity_type' => 'catalyst',
    'field_name' => 'field_block_placements',
    'label' => 'Placements',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'catalyst_block',
      'settings' => array(),
      'type' => 'block_placement_block_widget',
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'catalyst-block-field_block_preprocess'.
  $field_instances['catalyst-block-field_block_preprocess'] = array(
    'bundle' => 'block',
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
    'field_name' => 'field_block_preprocess',
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
          'layout_html' => 0,
          'php' => 'php',
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
        'rows' => 15,
      ),
      'type' => 'text_textarea',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'catalyst-block-field_catalyst_custom_css'.
  $field_instances['catalyst-block-field_catalyst_custom_css'] = array(
    'bundle' => 'block',
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
    'entity_type' => 'catalyst',
    'field_name' => 'field_catalyst_custom_css',
    'label' => 'Custom CSS',
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
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'catalyst-block-field_catalyst_custom_files'.
  $field_instances['catalyst-block-field_catalyst_custom_files'] = array(
    'bundle' => 'block',
    'deleted' => 0,
    'description' => 'Upload files that a specific to this block here.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'catalyst',
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
            'pathauto' => 0,
            'slashes' => 0,
            'transliterate' => 0,
          ),
          'value' => 'media/block/[field_block_machine]',
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
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'catalyst-block-field_catalyst_custom_js'.
  $field_instances['catalyst-block-field_catalyst_custom_js'] = array(
    'bundle' => 'block',
    'default_value' => NULL,
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
    'entity_type' => 'catalyst',
    'field_name' => 'field_catalyst_custom_js',
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
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'catalyst-block-field_catalyst_includes_css'.
  $field_instances['catalyst-block-field_catalyst_includes_css'] = array(
    'bundle' => 'block',
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
    'entity_type' => 'catalyst',
    'field_name' => 'field_catalyst_includes_css',
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
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'catalyst-block-field_catalyst_includes_js'.
  $field_instances['catalyst-block-field_catalyst_includes_js'] = array(
    'bundle' => 'block',
    'default_value' => NULL,
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
    'entity_type' => 'catalyst',
    'field_name' => 'field_catalyst_includes_js',
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
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'catalyst-block-field_catalyst_shared_files'.
  $field_instances['catalyst-block-field_catalyst_shared_files'] = array(
    'bundle' => 'block',
    'deleted' => 0,
    'description' => 'Existing shared files can be used without adding them here but by adding them here, you\'ll track the usage of each file.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'catalyst',
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
      'weight' => 17,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Content');
  t('Custom CSS');
  t('Custom Files');
  t('Custom Javascript');
  t('Existing shared files can be used without adding them here but by adding them here, you\'ll track the usage of each file.');
  t('Javascript Includes');
  t('Machine name');
  t('Placements');
  t('Preprocessing');
  t('Shared Files');
  t('Stylesheet Includes');
  t('Upload files that a specific to this block here.');

  return $field_instances;
}
