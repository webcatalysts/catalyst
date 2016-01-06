<?php
/**
 * @file
 * catalyst_template.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function catalyst_template_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_eck_bundle_info().
 */
function catalyst_template_eck_bundle_info() {
  $items = array(
    'catalyst_template' => array(
      'machine_name' => 'catalyst_template',
      'entity_type' => 'catalyst',
      'name' => 'template',
      'label' => 'Template',
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
