<?php
/**
 * @file
 * catalyst_template.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function catalyst_template_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'eck add catalyst template entities'.
  $permissions['eck add catalyst template entities'] = array(
    'name' => 'eck add catalyst template entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer catalyst template entities'.
  $permissions['eck administer catalyst template entities'] = array(
    'name' => 'eck administer catalyst template entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete catalyst template entities'.
  $permissions['eck delete catalyst template entities'] = array(
    'name' => 'eck delete catalyst template entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit catalyst template entities'.
  $permissions['eck edit catalyst template entities'] = array(
    'name' => 'eck edit catalyst template entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck list catalyst template entities'.
  $permissions['eck list catalyst template entities'] = array(
    'name' => 'eck list catalyst template entities',
    'roles' => array(),
    'module' => 'eck',
  );

  // Exported permission: 'eck view catalyst template entities'.
  $permissions['eck view catalyst template entities'] = array(
    'name' => 'eck view catalyst template entities',
    'roles' => array(),
    'module' => 'eck',
  );

  return $permissions;
}
