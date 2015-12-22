<?php
/**
 * @file
 * catalyst_media.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function catalyst_media_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function catalyst_media_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function catalyst_media_eck_bundle_info() {
  $items = array(
    'catalyst_file' => array(
      'machine_name' => 'catalyst_file',
      'entity_type' => 'catalyst',
      'name' => 'file',
      'label' => 'File',
      'config' => array(
        'managed_properties' => array(
          'title' => 'title',
          'created' => 0,
          'changed' => 0,
          'language' => 0,
        ),
      ),
    ),
    'catalyst_javascript' => array(
      'machine_name' => 'catalyst_javascript',
      'entity_type' => 'catalyst',
      'name' => 'javascript',
      'label' => 'Javascript',
      'config' => array(
        'managed_properties' => array(
          'title' => 'title',
          'created' => 0,
          'changed' => 0,
          'language' => 0,
        ),
      ),
    ),
    'catalyst_stylesheet' => array(
      'machine_name' => 'catalyst_stylesheet',
      'entity_type' => 'catalyst',
      'name' => 'stylesheet',
      'label' => 'Stylesheet',
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
