<?php
/**
 * @file
 * catalyst_menu.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function catalyst_menu_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer devel menu items'.
  $permissions['administer devel menu items'] = array(
    'name' => 'administer devel menu items',
    'roles' => array(),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer main-menu menu items'.
  $permissions['administer main-menu menu items'] = array(
    'name' => 'administer main-menu menu items',
    'roles' => array(
      'catalyst admin' => 'catalyst admin',
      'catalyst builder' => 'catalyst builder',
      'catalyst editor' => 'catalyst editor',
      'catalyst themer' => 'catalyst themer',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer management menu items'.
  $permissions['administer management menu items'] = array(
    'name' => 'administer management menu items',
    'roles' => array(),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'catalyst admin' => 'catalyst admin',
      'catalyst builder' => 'catalyst builder',
      'catalyst editor' => 'catalyst editor',
      'catalyst themer' => 'catalyst themer',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'administer navigation menu items'.
  $permissions['administer navigation menu items'] = array(
    'name' => 'administer navigation menu items',
    'roles' => array(),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: 'administer user-menu menu items'.
  $permissions['administer user-menu menu items'] = array(
    'name' => 'administer user-menu menu items',
    'roles' => array(
      'catalyst admin' => 'catalyst admin',
      'catalyst builder' => 'catalyst builder',
      'catalyst editor' => 'catalyst editor',
      'catalyst themer' => 'catalyst themer',
    ),
    'module' => 'menu_admin_per_menu',
  );

  return $permissions;
}
