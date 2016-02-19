<?php
/**
 * @file
 * catalyst_core.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function catalyst_core_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: catalyst_css
  $profiles['catalyst_css'] = array(
    'format' => 'catalyst_css',
    'editor' => 'ace',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 0,
      'add_to_summaries' => 1,
      'theme' => 'idle_fingers',
      'language' => 'en',
      'mode' => 'css',
      'keybinding' => '',
      'buttons' => array(),
      'css_setting' => 'theme',
      'css_path' => '',
      'advanced__active_tab' => 'edit-basic',
    ),
    'rdf_mapping' => array(),
  );

  // Exported profile: catalyst_doc
  $profiles['catalyst_doc'] = array(
    'format' => 'catalyst_doc',
    'editor' => 'ace',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 0,
      'add_to_summaries' => 1,
      'theme' => 'idle_fingers',
      'language' => 'en',
      'mode' => 'markdown',
      'keybinding' => '',
      'buttons' => array(),
      'css_setting' => 'theme',
      'css_path' => '',
      'advanced__active_tab' => 'edit-basic',
    ),
    'rdf_mapping' => array(),
  );

  // Exported profile: catalyst_html
  $profiles['catalyst_html'] = array(
    'format' => 'catalyst_html',
    'editor' => 'ace',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 0,
      'add_to_summaries' => 1,
      'theme' => 'idle_fingers',
      'language' => 'en',
      'mode' => 'html',
      'keybinding' => '',
      'buttons' => array(),
      'css_setting' => 'theme',
      'css_path' => '',
      'advanced__active_tab' => 'edit-basic',
    ),
    'rdf_mapping' => array(),
  );

  // Exported profile: catalyst_js
  $profiles['catalyst_js'] = array(
    'format' => 'catalyst_js',
    'editor' => 'ace',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 0,
      'add_to_summaries' => 1,
      'theme' => 'idle_fingers',
      'language' => 'en',
      'mode' => 'javascript',
      'keybinding' => '',
      'buttons' => array(),
      'css_setting' => 'theme',
      'css_path' => '',
      'advanced__active_tab' => 'edit-basic',
    ),
    'rdf_mapping' => array(),
  );

  // Exported profile: catalyst_php
  $profiles['catalyst_php'] = array(
    'format' => 'catalyst_php',
    'editor' => 'ace',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 0,
      'add_to_summaries' => 1,
      'theme' => 'idle_fingers',
      'language' => 'en',
      'mode' => 'php',
      'keybinding' => '',
      'buttons' => array(),
      'css_setting' => 'theme',
      'css_path' => '',
      'advanced__active_tab' => 'edit-basic',
    ),
    'rdf_mapping' => array(),
  );

  return $profiles;
}
