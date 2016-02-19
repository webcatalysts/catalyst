<?php
/**
 * @file
 * catalyst_core.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function catalyst_core_filter_default_formats() {
  $formats = array();

  // Exported format: Catalyst CSS.
  $formats['catalyst_css'] = array(
    'format' => 'catalyst_css',
    'name' => 'Catalyst CSS',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(),
  );

  // Exported format: Catalyst Doc.
  $formats['catalyst_doc'] = array(
    'format' => 'catalyst_doc',
    'name' => 'Catalyst Doc',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_markdown' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: Catalyst HTML.
  $formats['catalyst_html'] = array(
    'format' => 'catalyst_html',
    'name' => 'Catalyst HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(),
  );

  // Exported format: Catalyst Javascript.
  $formats['catalyst_js'] = array(
    'format' => 'catalyst_js',
    'name' => 'Catalyst Javascript',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(),
  );

  // Exported format: Catalyst PHP.
  $formats['catalyst_php'] = array(
    'format' => 'catalyst_php',
    'name' => 'Catalyst PHP',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(),
  );

  return $formats;
}
