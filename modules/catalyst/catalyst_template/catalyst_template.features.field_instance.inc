<?php
/**
 * @file
 * catalyst_template.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function catalyst_template_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'catalyst-template-field__blockplacements__layfield'.
  $field_instances['catalyst-template-field__blockplacements__layfield'] = array(
    'bundle' => 'template',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => NULL,
        'settings' => array(),
        'type' => 'block_placement_layout_field_formatter',
        'weight' => 8,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field__blockplacements__layfield',
    'label' => 'Block placements',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'catalyst_field_api',
      'settings' => array(),
      'type' => 'block_placement_layout_field_widget',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'catalyst-template-field__blocks_related'.
  $field_instances['catalyst-template-field__blocks_related'] = array(
    'bundle' => 'template',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'catalyst',
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
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'catalyst-template-field__css'.
  $field_instances['catalyst-template-field__css'] = array(
    'bundle' => 'template',
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
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field__css',
    'label' => 'Custom CSS',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'cpage_html' => 0,
          'css' => 'css',
          'html' => 0,
          'js' => 0,
          'layout_html' => 0,
          'php' => 0,
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
            'html' => array(
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
        'rows' => 8,
      ),
      'type' => 'text_textarea',
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'catalyst-template-field__debug'.
  $field_instances['catalyst-template-field__debug'] = array(
    'bundle' => 'template',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'default_value_function' => '',
    'default_value_php' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field__debug',
    'label' => 'Enable debugging',
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
      'weight' => 18,
    ),
  );

  // Exported field_instance: 'catalyst-template-field__files'.
  $field_instances['catalyst-template-field__files'] = array(
    'bundle' => 'template',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field__files',
    'label' => 'Custom Files',
    'required' => 1,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'gif jpg jpeg png svg m3u m4a mid mp3 wma wav 3gp avi flv swf mov mp4 mpg wmv eot ttf woff woff2 otf',
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
          'value' => 'media/template/[catalyst:field__template_entity_type]-[catalyst:field__template_bundle]',
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
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'catalyst-template-field__html_head'.
  $field_instances['catalyst-template-field__html_head'] = array(
    'bundle' => 'template',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field__html_head',
    'label' => 'Custom HTML Head',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'cpage_html' => 0,
          'css' => 0,
          'html' => 'html',
          'js' => 0,
          'layout_html' => 0,
          'php' => 0,
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
            'html' => array(
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
        'rows' => 8,
      ),
      'type' => 'text_textarea',
      'weight' => 16,
    ),
  );

  // Exported field_instance: 'catalyst-template-field__js'.
  $field_instances['catalyst-template-field__js'] = array(
    'bundle' => 'template',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field__js',
    'label' => 'Custom Javascript',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'cpage_html' => 0,
          'css' => 0,
          'html' => 0,
          'js' => 'js',
          'layout_html' => 0,
          'php' => 0,
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
            'html' => array(
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
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'catalyst-template-field__layout'.
  $field_instances['catalyst-template-field__layout'] = array(
    'bundle' => 'template',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field__layout',
    'label' => 'Layout',
    'required' => 0,
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

  // Exported field_instance: 'catalyst-template-field__media_files'.
  $field_instances['catalyst-template-field__media_files'] = array(
    'bundle' => 'template',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'catalyst',
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
      'weight' => 20,
    ),
  );

  // Exported field_instance: 'catalyst-template-field__media_javascripts'.
  $field_instances['catalyst-template-field__media_javascripts'] = array(
    'bundle' => 'template',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 4,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field__media_javascripts',
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
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'catalyst-template-field__media_stylesheets'.
  $field_instances['catalyst-template-field__media_stylesheets'] = array(
    'bundle' => 'template',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'link' => FALSE,
        ),
        'type' => 'entityreference_label',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field__media_stylesheets',
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
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'catalyst-template-field__preprocess'.
  $field_instances['catalyst-template-field__preprocess'] = array(
    'bundle' => 'template',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field__preprocess',
    'label' => 'Preprocessing',
    'required' => 0,
    'settings' => array(
      'better_formats' => array(
        'allowed_formats' => array(
          'cpage_html' => 0,
          'css' => 0,
          'html' => 0,
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
              'weight' => 0,
            ),
            'css' => array(
              'weight' => -9,
            ),
            'html' => array(
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
      'weight' => 17,
    ),
  );

  // Exported field_instance: 'catalyst-template-field__template_bundle'.
  $field_instances['catalyst-template-field__template_bundle'] = array(
    'bundle' => 'template',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
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
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field__template_bundle',
    'label' => 'Bundle',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'machine',
      'settings' => array(
        'editable' => 1,
        'field_size' => 60,
        'machine_field_label' => 'Machine name',
        'machine_replace_pattern' => '[^a-z0-9_]+',
        'machine_replace_with' => '_',
      ),
      'type' => 'machine_default_widget',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'catalyst-template-field__template_entity_type'.
  $field_instances['catalyst-template-field__template_entity_type'] = array(
    'bundle' => 'template',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'machine',
        'settings' => array(),
        'type' => 'machine_default',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'catalyst',
    'field_name' => 'field__template_entity_type',
    'label' => 'Entity type',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'machine',
      'settings' => array(
        'editable' => 1,
        'field_size' => 60,
        'machine_field_label' => 'Machine name',
        'machine_replace_pattern' => '[^a-z0-9_]+',
        'machine_replace_with' => '_',
      ),
      'type' => 'machine_default_widget',
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add Blocks');
  t('Block placements');
  t('Bundle');
  t('Custom CSS');
  t('Custom Files');
  t('Custom HTML Head');
  t('Custom Javascript');
  t('Enable debugging');
  t('Entity type');
  t('Javascript Includes');
  t('Layout');
  t('Preprocessing');
  t('Shared Files');
  t('Stylesheet Includes');

  return $field_instances;
}
