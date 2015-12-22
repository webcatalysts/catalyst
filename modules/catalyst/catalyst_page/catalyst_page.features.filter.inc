<?php
/**
 * @file
 * catalyst_page.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function catalyst_page_filter_default_formats() {
  $formats = array();

  // Exported format: Page HTML.
  $formats['cpage_html'] = array(
    'format' => 'cpage_html',
    'name' => 'Page HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => 0,
    'filters' => array(
      'filter_htmlcorrector' => array(
        'weight' => -44,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  return $formats;
}
