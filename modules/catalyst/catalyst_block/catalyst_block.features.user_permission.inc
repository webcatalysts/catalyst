<?php
/**
 * @file
 * catalyst_block.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function catalyst_block_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'eck add catalyst block entities'.
  $permissions['eck add catalyst block entities'] = array(
    'name' => 'eck add catalyst block entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer catalyst block entities'.
  $permissions['eck administer catalyst block entities'] = array(
    'name' => 'eck administer catalyst block entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete catalyst block entities'.
  $permissions['eck delete catalyst block entities'] = array(
    'name' => 'eck delete catalyst block entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit catalyst block entities'.
  $permissions['eck edit catalyst block entities'] = array(
    'name' => 'eck edit catalyst block entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck list catalyst block entities'.
  $permissions['eck list catalyst block entities'] = array(
    'name' => 'eck list catalyst block entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck view catalyst block entities'.
  $permissions['eck view catalyst block entities'] = array(
    'name' => 'eck view catalyst block entities',
    'roles' => array(),
    'module' => 'eck',
  );

  return $permissions;
}
