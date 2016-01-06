<?php

/**
 * @file
 * ECK related functions and callacks for Catalyst Admin.
 *
 * This may get refactored with hook_catalyst_plugin_info() and
 * hook_entity_info_alter().
 */

function catalyst_admin_alter_eck_entity_menu(&$items, $bundle, $prefix = 'admin/structure', $view = TRUE) {
  $prefix .= '/' . $bundle;
  // Duplicate entity add menu item
  $items[$prefix .'/add'] = $items['admin/structure/entity-type/catalyst/' . $bundle . '/add'];

  // This happens to work because we're trying to find the number of the
  // %eckentity argument which is added right after the suffix
  // Otherwise 1 would need to be subtracted
  $arg_num = count(explode('/', $prefix));

  foreach (array('edit', 'delete') AS $action) {
    $items[$prefix . '/%eckentity/' . $action] = array_merge(
      $items['catalyst/' . $bundle . '/%eckentity/' . $action],
      array(
        'access arguments' => array($action, 'catalyst', $bundle, $arg_num),
        'page arguments' => array('catalyst', $bundle, $arg_num),
      )
    );
    // Remove frontend edit/delete
    unset($items['catalyst/' . $bundle . '/%eckentity/' . $action]);
  }
  // Move delete to the end
  $items[$prefix . '/%eckentity/delete']['weight'] = 100;

  if ($view) {
    // Replace the view menu item
    $items[$prefix . '/%eckentity'] = array_merge(
      $items['catalyst/' . $bundle . '/%eckentity'],
      array(
        'title callback' => 'node_page_title',
        'title arguments' => array($arg_num),
        'access arguments' => array('view', 'catalyst', $bundle, $arg_num),
        'page arguments' => array('catalyst', $bundle, $arg_num),
      )
    );
    // Replace the view menu item tab
    $items[$prefix . '/%eckentity/view'] = $items['catalyst/' . $bundle . '/%eckentity/view'];
  }
  else {
    $items[$prefix . '/%eckentity'] = array_merge(
      $items['catalyst/' . $bundle . '/%eckentity'],
      $items[$prefix . '/%eckentity/edit'],
      array(
        'title callback' => 'node_page_title',
        'title arguments' => array($arg_num),
        'type' => MENU_NORMAL_ITEM,
      )
    );
    $items[$prefix . '/%eckentity/edit'] = array(
      'title' => 'Edit',
    ) + $items['catalyst/' . $bundle . '/%eckentity/view'];
  }

  // Remove frontend view and tab menu items
  unset(
    $items['catalyst/' . $bundle . '/%eckentity'],
    $items['catalyst/' . $bundle . '/%eckentity/view']
  );
}

function catalyst_admin_eck_url_outbound($bundle, &$path, &$options, $original_path, $prefix = 'admin/structure') {
  $m = array();
  // Match catalyst/[bundle]/[entity id]
  if (preg_match('/catalyst\/' . $bundle . '\/([0-9]+)(.*)/i', $path, $m)) {
    // Alter the path according the provided arguments
    $path = $prefix . '/' . $bundle . '/' . $m[1] . $m[2];
  }
}
