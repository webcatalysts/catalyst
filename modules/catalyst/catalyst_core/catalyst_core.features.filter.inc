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

  // Exported format: PHP.
  $formats['php'] = array(
    'format' => 'php',
    'name' => 'PHP',
    'cache' => 1,
    'status' => 1,
    'weight' => -5,
    'filters' => array(),
  );

  return $formats;
}
