<?php
/**
 * @file
 * catalyst_doctype.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function catalyst_doctype_ctools_plugin_api($module = NULL, $api = NULL) {
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
function catalyst_doctype_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_eck_bundle_info().
 */
function catalyst_doctype_eck_bundle_info() {
  $items = array(
    'catalyst_doctype' => array(
      'machine_name' => 'catalyst_doctype',
      'entity_type' => 'catalyst',
      'name' => 'doctype',
      'label' => 'Doctype',
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
