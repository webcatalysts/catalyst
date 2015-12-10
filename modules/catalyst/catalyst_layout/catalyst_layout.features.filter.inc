<?php
/**
 * @file
 * catalyst_layout.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function catalyst_layout_filter_default_formats() {
  $formats = array();

  // Exported format: Layout HTML.
  $formats['layout_html'] = array(
    'format' => 'layout_html',
    'name' => 'Layout HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'ace_editor' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(
          'autocomplete' => TRUE,
          'autowrap' => TRUE,
          'font-size' => '12pt',
          'height' => '200px',
          'invisibles' => FALSE,
          'line-numbers' => 1,
          'linehighlighting' => 1,
          'print-margin' => FALSE,
          'syntax' => 'html',
          'theme' => 'cobalt',
          'width' => '100%',
        ),
      ),
      'twig' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
