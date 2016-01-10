<?php
/**
 * @file
 * catalyst_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function catalyst_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function catalyst_page_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function catalyst_page_node_info() {
  $items = array(
    'cpage' => array(
      'name' => t('Advanced Page'),
      'base' => 'node_content',
      'description' => t('A catalyst page provides an advanced feature set that facilitates simple to advanced pages.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
