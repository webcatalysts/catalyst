<?php
/**
 * @file
 * catalyst_schema.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function catalyst_schema_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'eck add catalyst schema entities'.
  $permissions['eck add catalyst schema entities'] = array(
    'name' => 'eck add catalyst schema entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer catalyst schema entities'.
  $permissions['eck administer catalyst schema entities'] = array(
    'name' => 'eck administer catalyst schema entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete catalyst schema entities'.
  $permissions['eck delete catalyst schema entities'] = array(
    'name' => 'eck delete catalyst schema entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit catalyst schema entities'.
  $permissions['eck edit catalyst schema entities'] = array(
    'name' => 'eck edit catalyst schema entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck list catalyst schema entities'.
  $permissions['eck list catalyst schema entities'] = array(
    'name' => 'eck list catalyst schema entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck view catalyst schema entities'.
  $permissions['eck view catalyst schema entities'] = array(
    'name' => 'eck view catalyst schema entities',
    'roles' => array(),
    'module' => 'eck',
  );

  return $permissions;
}
