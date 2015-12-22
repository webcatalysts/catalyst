<?php
/**
 * @file
 * catalyst_layout.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function catalyst_layout_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: layout_html
  $profiles['layout_html'] = array(
    'format' => 'layout_html',
    'editor' => 'ace',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 1,
      'add_to_summaries' => 1,
      'theme' => 'idle_fingers',
      'language' => 'en',
      'mode' => 'twig',
      'keybinding' => '',
      'buttons' => array(
        'default' => array(
          'fullscreen' => 1,
        ),
      ),
      'css_setting' => 'theme',
      'css_path' => '',
      'advanced__active_tab' => 'edit-basic',
    ),
  );

  return $profiles;
}
