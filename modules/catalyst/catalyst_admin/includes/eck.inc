<?php

/**
 * @file
 * ECK related functions and callacks for Catalyst Admin.
 *
 * This may get refactored with hook_catalyst_plugin_info() and
 * hook_entity_info_alter().
 */

/**
 *
 */
function catalyst_admin_eck_entity_info_alter(&$entity_info) {
  // Reset the access callback which is overriden in catalyst_core
  $entity_info['catalyst']['access callback'] = 'eck__entity_access';
  $plugins = catalyst_get_plugin_info();
  foreach ($plugins AS $plugin => $plugin_info) {
    if ($crud_info = catalyst_admin_plugin_eck_crud($plugin_info)) {
      $entity_type = $plugin_info['entity_type'];
      $bundle = $plugin_info['bundle'];
      foreach (array('add', 'edit', 'view', 'delete') AS $action) {
        if (isset($crud_info[$action]['menu_item'])) {
          unset($crud_info[$action]['menu_item']);
        }
        catalyst_array_merge(
          $entity_info[$entity_type]['bundles'][$bundle]['crud'][$action],
          $crud_info[$action]
        );
      }
      if (isset($crud_info['admin']['menu_item'])) {
        unset($crud_info['admin']['menu_item']);
      }
      catalyst_array_merge(
        $entity_info[$entity_type]['bundles'][$bundle]['admin'],
        $crud_info['admin']
      );
    }
  }
}

function catalyst_admin_eck__entity_menu_alter(&$menu_items) {
  $plugins = catalyst_get_plugin_info();
  $menu_item_defaults = array(
    'add' => array(),
    'admin' => array(),
    'delete' => array(
      'title' => t('Delete'),
      'type' => MENU_LOCAL_TASK,
      'weight' => 10,
    ),
    'view' => array(
      'type' => MENU_LOCAL_TASK,
      'title' => t('View'),
    ),
    'edit' => array(
      'type' => MENU_DEFAULT_LOCAL_TASK,
      'weight' => -10,
    ),
  );
  foreach ($plugins AS $plugin => $plugin_info) {
    if ($crud_info = catalyst_admin_plugin_eck_crud($plugin_info)) {
      $path = $crud_info['admin']['path'];
      $menu_item_overrides = $menu_item_defaults['admin'];
      if (isset($crud_info['admin']['menu_item'])) {
        catalyst_array_merge($menu_item_overrides, $crud_info['admin']['menu_item']);
      }
      catalyst_array_merge($menu_items[$path], $menu_item_overrides);
      if (isset($crud_info['admin']['parent_menu_item'])) {
        $parent_menu_item = $crud_info['admin']['parent_menu_item'];
        $parent_menu_path = $parent_menu_item['path'];
        unset($parent_menu_item['path']);
        catalyst_array_merge($menu_items[$parent_menu_path], $parent_menu_item);
      }
      foreach (array('add', 'edit', 'view', 'delete') AS $action) {
        $path = $crud_info[$action]['path'];
        if (isset($crud_info[$action]['menu_item']) && $crud_info[$action]['menu_item'] === FALSE) {
          // Allow plugins to declare the menu item should not exist
          unset($menu_items[$path]);
          continue;
        }
        $menu_items[$path]['access callback'] = 'catalyst_admin_eck__entity_menu_access';
        $menu_item_overrides = $menu_item_defaults[$action];
        if (isset($crud_info[$action]['menu_item'])) {
          catalyst_array_merge($menu_item_overrides, $crud_info[$action]['menu_item']);
        }
        catalyst_array_merge($menu_items[$path], $menu_item_overrides);
        if (isset($menu_items[$path]['type']) && $menu_items[$path]['type'] == MENU_DEFAULT_LOCAL_TASK) {
          $menu_items[$path]['type'] = MENU_NORMAL_ITEM;
          $menu_items[$path . '/' . $action] = array(
            'type' => MENU_DEFAULT_LOCAL_TASK,
            'title' => ucfirst($action),
          );
          $parts = explode('/', $path);
          for ($eck_arg_num = 0; $eck_arg_num < count($parts); $eck_arg_num++) {
            if ($parts[$eck_arg_num] == '%eckentity') {
              break;
            }
          }
          $menu_items[$path]['title callback'] = 'node_page_title';
          $menu_items[$path]['title arguments'] = array($eck_arg_num);
        }
      }
      foreach (array('view', 'edit', 'delete') AS $subaction) {
        unset($menu_items[$crud_info['view']['path'] . '/' . $subaction]);
      }
    }
  }
}

function catalyst_admin_plugin_eck_crud($info) {
  if (isset($info['entity_type']) && isset($info['bundle']) && isset($info['crud'])) {
    return $info['crud'];
  }
}

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
