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

  // Exported profile: catalyst_css.
  $profiles['catalyst_css'] = array(
    'format' => 'catalyst_css',
    'editor' => 'ace',
    'settings' => array(
      'theme' => 'idle_fingers',
      'language' => 'en',
      'mode' => 'css',
      'keybinding' => '',
      'buttons' => array(),
      'css_setting' => 'theme',
      'css_path' => '',
      'advanced__active_tab' => 'edit-basic',
    ),
    'preferences' => array(
      'add_to_summaries' => 1,
      'default' => 1,
      'show_toggle' => 0,
      'user_choose' => 0,
      'version' => NULL,
    ),
    'name' => 'formatcatalyst_css',
  );

  // Exported profile: catalyst_doc.
  $profiles['catalyst_doc'] = array(
    'format' => 'catalyst_doc',
    'editor' => 'ace',
    'settings' => array(
      'theme' => 'github',
      'language' => 'en',
      'mode' => 'markdown',
      'keybinding' => '',
      'buttons' => array(),
      'css_setting' => 'theme',
      'css_path' => '',
      'advanced__active_tab' => 'edit-basic',
    ),
    'preferences' => array(
      'add_to_summaries' => 1,
      'default' => 1,
      'show_toggle' => 0,
      'user_choose' => 0,
      'version' => NULL,
    ),
    'name' => 'formatcatalyst_doc',
  );

  // Exported profile: catalyst_html.
  $profiles['catalyst_html'] = array(
    'format' => 'catalyst_html',
    'editor' => 'ace',
    'settings' => array(
      'theme' => 'idle_fingers',
      'language' => 'en',
      'mode' => 'html',
      'keybinding' => '',
      'buttons' => array(),
      'css_setting' => 'theme',
      'css_path' => '',
      'advanced__active_tab' => 'edit-basic',
    ),
    'preferences' => array(
      'add_to_summaries' => 1,
      'default' => 1,
      'show_toggle' => 0,
      'user_choose' => 0,
      'version' => NULL,
    ),
    'name' => 'formatcatalyst_html',
  );

  // Exported profile: catalyst_js.
  $profiles['catalyst_js'] = array(
    'format' => 'catalyst_js',
    'editor' => 'ace',
    'settings' => array(
      'theme' => 'idle_fingers',
      'language' => 'en',
      'mode' => 'javascript',
      'keybinding' => '',
      'buttons' => array(),
      'css_setting' => 'theme',
      'css_path' => '',
      'advanced__active_tab' => 'edit-basic',
    ),
    'preferences' => array(
      'add_to_summaries' => 1,
      'default' => 1,
      'show_toggle' => 0,
      'user_choose' => 0,
      'version' => NULL,
    ),
    'name' => 'formatcatalyst_js',
  );

  // Exported profile: catalyst_php.
  $profiles['catalyst_php'] = array(
    'format' => 'catalyst_php',
    'editor' => 'ace',
    'settings' => array(
      'theme' => 'idle_fingers',
      'language' => 'en',
      'mode' => 'php',
      'keybinding' => '',
      'buttons' => array(),
      'css_setting' => 'theme',
      'css_path' => '',
      'advanced__active_tab' => 'edit-basic',
    ),
    'preferences' => array(
      'add_to_summaries' => 1,
      'default' => 1,
      'show_toggle' => 0,
      'user_choose' => 0,
      'version' => NULL,
    ),
    'name' => 'formatcatalyst_php',
  );

  return $profiles;
}
