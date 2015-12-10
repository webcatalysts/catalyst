<?php
/**
 * @file
 * catalyst_media.features.inc
 */

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
      'config' => array(),
    ),
    'catalyst_javascript' => array(
      'machine_name' => 'catalyst_javascript',
      'entity_type' => 'catalyst',
      'name' => 'javascript',
      'label' => 'Javascript',
      'config' => array(),
    ),
    'catalyst_stylesheet' => array(
      'machine_name' => 'catalyst_stylesheet',
      'entity_type' => 'catalyst',
      'name' => 'stylesheet',
      'label' => 'Stylesheet',
      'config' => array(),
    ),
  );
  return $items;
}
