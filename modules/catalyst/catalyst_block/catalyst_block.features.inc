<?php
/**
 * @file
 * catalyst_block.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function catalyst_block_ctools_plugin_api($module = NULL, $api = NULL) {
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
function catalyst_block_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function catalyst_block_eck_bundle_info() {
  $items = array(
    'catalyst_block' => array(
      'machine_name' => 'catalyst_block',
      'entity_type' => 'catalyst',
      'name' => 'block',
      'label' => 'Block',
      'config' => array(
        'managed_properties' => array(
          'title' => 'title',
          'created' => 0,
          'changed' => 0,
          'language' => 0,
        ),
      ),
    ),
  );
  return $items;
}
