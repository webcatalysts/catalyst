<?php
/**
 * @file
 * catalyst_admin.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function catalyst_admin_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access navbar'.
  $permissions['access navbar'] = array(
    'name' => 'access navbar',
    'roles' => array(
      'admin' => 'admin',
      'builder' => 'builder',
      'editor' => 'editor',
      'themer' => 'themer',
      'uadmin' => 'uadmin',
    ),
    'module' => 'navbar',
  );

  // Exported permission: 'administer shortcut per role'.
  $permissions['administer shortcut per role'] = array(
    'name' => 'administer shortcut per role',
    'roles' => array(),
    'module' => 'shortcutperrole',
  );

  // Exported permission: 'administer shortcuts'.
  $permissions['administer shortcuts'] = array(
    'name' => 'administer shortcuts',
    'roles' => array(),
    'module' => 'shortcut',
  );

  // Exported permission: 'customize shortcut links'.
  $permissions['customize shortcut links'] = array(
    'name' => 'customize shortcut links',
    'roles' => array(),
    'module' => 'shortcut',
  );

  // Exported permission: 'switch shortcut sets'.
  $permissions['switch shortcut sets'] = array(
    'name' => 'switch shortcut sets',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'shortcut',
  );

  return $permissions;
}
