<?php

/**
 * @file
 * Menu related functions for Catalyst.
 *
 * Functions defined here avoid being prefixed as "catalyst_menu_" to
 * help distinguish between functions provided by catalyst_core and
 * catalyst_menu.
 *
 * Usage:
 * @code
 * catalyst_include('menu');
 * @endcode
 *
 * @todo Replicate the menu_block functions used by catalyst and remove
 *   menu_block module.
 */

/**
 * Load all catalyst menus.
 */
function catalyst_load_menus() {
  return array_diff_key(menu_load_all(), catalyst_list_ignore_menus());
}

/**
 * Load only custom menus.
 */
function catalyst_load_custom_menus() {
  return array_diff_key(catalyst_load_menus(), catalyst_list_system_menus());
}

/**
 * Load menu links by menu_name with static caching.
 *
 * @menu_load_links()
 */
function catalyst_load_menu_links($menu_name, $reset = FALSE) {
  $stored_links = &drupal_static(__FUNCTION__);
  if (!isset($stored_links)) {
    $stored_links = array();
  }
  if ($reset || !isset($stored_links[$menu_name])) {
    $stored_links[$menu_name] = menu_load_links($menu_name);
  }
  return $stored_links[$menu_name];
}

/**
 * List of system menus.
 *
 * These menus are not available for export but the corresponding menu links
 * are candidates for export.
 */
function catalyst_list_system_menus() {
  return array(
    'user-menu' => 'User menu',
    'main-menu' => 'Main menu',
  );
}

/**
 * List of menus that catalyst will ignore.
 *
 * These menus are not available for export nor are their menu items. Nodes
 * will not be able to be assigned to these menus through the node form.
 *
 * @see hook_catalyst_ignore_menus_alter().
 */
function catalyst_list_ignore_menus($reset = FALSE) {
  $ignore_menus = &drupal_static(__FUNCTION__);
  if ($reset || !isset($ignore_menus)) {
    // Allow modules to define and all ignored menus
    $ignore_menus = array_diff_key(menu_list_system_menus(), catalyst_list_system_menus());
    drupal_alter('catalyst_ignore_menus', $ignore_menus);
  }
  return $ignore_menus;
}
