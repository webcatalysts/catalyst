<?php

/**
 * @file
 * Features integration for Menu Lockdown.
 *
 * Allows exporting Menu Lockdown suggestions that aren't already suggested
 * by other modules.
 */

/**
 * Implements hook_features_export().
 */
function menu_lockdown_features_export($data, &$export, $module_name) {
  $export['dependencies']['menu_lockdown'] = 'menu_lockdown';
  foreach ($data AS $path) {
    $export['features']['menu_lockdown'][$path] = $path;
  }
  return array();
}

/**
 * Implements hook_features_export_options().
 */
function menu_lockdown_features_export_options() {
  $options = array();
  // Combine our suggestions to ignore items on either list.
  $suggestions = array_merge(
    menu_lockdown_suggestions('whitelist'),
    menu_lockdown_suggestions('blacklist')
  );
  foreach (array('whitelist', 'blacklist') AS $list) {
    if ($items = variable_get('menu_lockdown_' . $list, FALSE)) {
      // Loop the items in each list
      foreach ($items AS $path) {
        $path = trim($path);
        if (!in_array($path, $suggestions)) {
          // Provide paths that aren't already suggested as an option for
          // features.
          $options[$path] = format_string('@path (@menu_lockdown_list)', array(
           '@path' => $path,
           '@menu_lockdown_list' => $list,
          ));
        }
      }
    }
  }
  return $options;
}

/**
 * Implements hook_features_export_render().
 */
function menu_lockdown_features_export_render($module_name, $data, $export = NULL) {
  $whitelist = variable_get('menu_lockdown_whitelist', array());
  $blacklist = variable_get('menu_lockdown_blacklist', array());
  // Re-separate $data between blacklist and whitelist
  $_data = array();
  foreach ($data AS $path) {
    if (in_array($path, $whitelist)) {
      $_data['whitelist'][] = $path;
      continue;
    }
    $_data['blacklist'][] = $path;
  }

  $code = array();
  $code[] = '  return array(';
  if (isset($_data['whitelist'])) {
    $code[] = '    MENU_LOCKDOWN_WHITELIST => array(';
    foreach ($_data['whitelist'] AS $path) {
      $code[] = '      \''. $path . '\',';
    }
    $code[] = '    ),';
  }
  if (isset($_data['blacklist'])) {
    $code[] = '    MENU_LOCKDOWN_BLACKLIST => array(';
    foreach ($_data['blacklist'] AS $path) {
      $code[] = '      \''. $path . '\',';
    }
    $code[] = '    ),';
  }
  $code[] = '  );';
  return array('menu_lockdown_suggestions' => implode("\n", $code));
}
