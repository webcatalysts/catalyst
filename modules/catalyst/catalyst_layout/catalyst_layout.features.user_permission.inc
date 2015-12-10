<?php
/**
 * @file
 * catalyst_layout.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function catalyst_layout_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'eck add catalyst layout entities'.
  $permissions['eck add catalyst layout entities'] = array(
    'name' => 'eck add catalyst layout entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer catalyst layout entities'.
  $permissions['eck administer catalyst layout entities'] = array(
    'name' => 'eck administer catalyst layout entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete catalyst layout entities'.
  $permissions['eck delete catalyst layout entities'] = array(
    'name' => 'eck delete catalyst layout entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit catalyst layout entities'.
  $permissions['eck edit catalyst layout entities'] = array(
    'name' => 'eck edit catalyst layout entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck list catalyst layout entities'.
  $permissions['eck list catalyst layout entities'] = array(
    'name' => 'eck list catalyst layout entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck view catalyst layout entities'.
  $permissions['eck view catalyst layout entities'] = array(
    'name' => 'eck view catalyst layout entities',
    'roles' => array(),
    'module' => 'eck',
  );

  return $permissions;
}
