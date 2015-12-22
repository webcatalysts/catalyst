<?php

/**
 * @file
 * WYSIWYG plugin for the Ace code editor.
 */

function wysiwyg_ace_ace_editor() {
  return array(
    'ace' => array(
      'title' => 'ACE code editor',
      'vendor url' => 'https://ace.c9.io/',
      'download url' => 'https://github.com/ajaxorg/ace-builds/',
      'libraries' => array(
        '' => array(
          'title' => 'Source',
          'files' => array(
            'src/ace.js',
          ),
        ),
      ),
      'version callback' => 'wysiwyg_ace_version',
      'themes callback' => 'wysiwyg_ace_themes',
      'settings form callback' => 'wysiwyg_ace_settings_form',
      'load callback' => 'wysiwyg_ace_load',
      'settings callback' => 'wysiwyg_ace_settings',
      'plugin callback' => '_wysiwyg_ace_plugins',
      'versions' => array(
        '1.2.1' => array(
          'js files' => array('ace.js'),
          'css files' => array('ace.css'),
        ),
      ),
    ),
  );
}

function wysiwyg_ace_version() {
  return '1.2.1';
}

function wysiwyg_ace_settings($editor, $config, $theme) {
  return $config + wysiwyg_ace_default_settings();
}

function wysiwyg_ace_default_settings() {
  return array(
    'animate_scroll' => FALSE,
    // markbegin, markbeginend, manual
    'fold_widgets' => 'markbeginend',
    'fold_widgets_fade' => TRUE,
    'fontfont' => 12,
    'gutter' => TRUE,
    'indent_guildes' => TRUE,
    'invisibles' => TRUE,
    'highlight_active_line' => TRUE,
    // Scrolling
    'hscroll_always' => FALSE,
    'vscroll_always' => FALSE,
    'scroll_past_end' => FALSE,
    'mode' => 'html',
    'keybinding' => NULL,
    'print_margin' => TRUE,
    'selection_style' => 'line',
    // Tabbing
    //'elastic_tabstops' => TRUE,
    'tab_soft' => TRUE,
    'tab_size' => 2,
    'theme' => 'cobalt',
    'wrap' => TRUE,
    'resizable' => TRUE,
    'toolbar' => FALSE,
  );
  return $settings;
}

function wysiwyg_ace_themes() {
  return _wysiwyg_ace_options('theme');
}
function wysiwyg_ace_modes() {
  return _wysiwyg_ace_options('mode');
}

function _wysiwyg_ace_options($type) {
  $library_path = DRUPAL_ROOT . '/' . libraries_get_path('ace') . '/src';
  $files = array_keys(file_scan_directory($library_path, '/^' . $type . '-.*\.js$/i'));
  $themes = array();
  foreach ($files AS $filepath) {
    $theme = preg_replace('/^'. $type . '\-/', '', basename($filepath, '.js'));
    $themes[] = $theme;
  }
  return $themes;
}

function wysiwyg_ace_settings_form(&$form, &$form_state) {
  dsm($form);
  $args = func_get_args();
  dsm($args);
  $profile = $form_state['wysiwyg_profile'];
  $settings = $profile->settings + wysiwyg_ace_default_settings();

  $themes = wysiwyg_ace_themes();
  $form['basic']['theme'] = array(
    '#type' => 'select',
    '#title' => t('Default Theme'),
    '#options' => array_combine($themes, $themes),
    '#default_value' => $settings['theme'],
    '#weight' => -300,
  );

  $modes = wysiwyg_ace_modes();
  $form['basic']['mode'] = array(
    '#type' => 'select',
    '#title' => t('Default Mode'),
    '#options' => array_combine($modes, $modes),
    '#default_value' => $settings['mode'],
    '#weight' => -400,
  );

  $form['basic']['keybinding'] = array(
    '#type' => 'select',
    '#title' => t('Default Key Binding'),
    '#options' => array('' => t('None')) + _wysiwyg_ace_options('keybinding'),
    '#default_value' => $settings['keybinding'],
    '#weight' => -200,
  );

  $form['css']['#access'] = FALSE;
}

function _wysiwyg_ace_plugins($editor) {
  return array(
    'default' => array(
      'buttons' => array(
        'fullscreen' => t('Fullscreen'),
      ),
    ),
  );
}
