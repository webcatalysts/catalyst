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
    'filters' => array(),
  );

  return $formats;
}
