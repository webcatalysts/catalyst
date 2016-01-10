<?php

/**
 * @file
 * Catalyst hook implementations for Catalyst Menu.
 *
 * @see catalyst.api.php
 */

/**
 * Implements hook_catalyst_plugin_info().
 */
function catalyst_menu_catalyst_plugin_info() {
  return array(
    'menu' => array(
      'title' => t('Menus'),
      'exportables' => TRUE,
      'migration' => array(
        'class_name' => 'CatalystMenuMigration',
      ),
      'weight' => 10,
    ),
    'menu_link' => array(
      'title' => t('Menu Links'),
      'exportables' => TRUE,
      'migration' => array(
        'class_name' => 'CatalystMenuLinkMigration',
      ),
      'migration sources' => array('cpage'),
      'weight' => 11,
    ),
  );
}

/**
 * Implements hook_catalyst_export_candidates().
 */
function catalyst_menu_catalyst_export_candidates($group) {
  $candidates = array();
  switch ($group['type']) {
    // Menu candidates (custom menus)
    case 'menu':
      catalyst_include('menu');
      $custom_menus = catalyst_load_custom_menus();
      foreach ($custom_menus AS $menu_name => $menu) {
        $candidates[] = array(
          'id' => $menu_name,
          'label' => $menu['title'],
          'export' => $menu,
        );
      }
      break;
    // Menu link candidates
    case 'menu_link':
      catalyst_include('menu');
      foreach (array_keys(catalyst_load_custom_menus()) AS $menu_name) {
        foreach (catalyst_load_menu_links($menu_name) AS $menu_link) {
          switch (true) {
            // Skip all node menu links. Modules implementing exportable nodes
            // like catalyst_page should provide their own menu link candidates
            case $menu_link['router_path'] == 'node/%':
            // Skip system menu links that aren't customized and all node menu
            case $menu_link['module'] == 'system' && !$menu_link['customized']:
              continue;
          }
          $candidates[] = array(
            'id' => $menu_link['mlid'],
            'label' => $menu_link['link_title'],
            'export' => $menu_link,
          );
        }
      }
      break;
  }
  return $candidates;
}

/**
 * Implements hook_catalyst_export_dependencies().
 */
function catalyst_menu_catalyst_export_dependencies($export, $group) {
  $dependencies = array();
  if ($group['type'] == 'menu_link') {
    catalyst_include('menu');
    // Detect menu dependancies for menu links in custom menus
    if (!in_array($export->menu_name, array_keys(catalyst_list_system_menus()))) {
      catalyst_add_export($dependencies, 'menu', $export->menu_name);
    }
    // Detect parent menu links
    if ($export->plid) {
      catalyst_add_export($dependencies, 'menu_link', $export->plid);
    }
  }
  return $dependencies;
}
