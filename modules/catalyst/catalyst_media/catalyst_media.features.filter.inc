<?php
/**
 * @file
 * catalyst_media.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function catalyst_media_filter_default_formats() {
  $formats = array();

  // Exported format: CSS.
  $formats['css'] = array(
    'format' => 'css',
    'name' => 'CSS',
    'cache' => 1,
    'status' => 1,
    'weight' => -9,
    'filters' => array(),
  );

  // Exported format: Javascript.
  $formats['js'] = array(
    'format' => 'js',
    'name' => 'Javascript',
    'cache' => 1,
    'status' => 1,
    'weight' => -8,
    'filters' => array(),
  );

  return $formats;
}
