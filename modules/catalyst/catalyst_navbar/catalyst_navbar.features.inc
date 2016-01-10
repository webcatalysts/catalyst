<?php
/**
 * @file
 * catalyst_navbar.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function catalyst_navbar_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
