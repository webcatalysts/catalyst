<?php
/**
 * @file
 * catalyst_doctype.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function catalyst_doctype_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'eck add catalyst doctype entities'.
  $permissions['eck add catalyst doctype entities'] = array(
    'name' => 'eck add catalyst doctype entities',
    'roles' => array(
      'admin' => 'admin',
      'builder' => 'builder',
      'themer' => 'themer',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer catalyst doctype entities'.
  $permissions['eck administer catalyst doctype entities'] = array(
    'name' => 'eck administer catalyst doctype entities',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete catalyst doctype entities'.
  $permissions['eck delete catalyst doctype entities'] = array(
    'name' => 'eck delete catalyst doctype entities',
    'roles' => array(
      'admin' => 'admin',
      'builder' => 'builder',
      'themer' => 'themer',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit catalyst doctype entities'.
  $permissions['eck edit catalyst doctype entities'] = array(
    'name' => 'eck edit catalyst doctype entities',
    'roles' => array(
      'admin' => 'admin',
      'builder' => 'builder',
      'themer' => 'themer',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list catalyst doctype entities'.
  $permissions['eck list catalyst doctype entities'] = array(
    'name' => 'eck list catalyst doctype entities',
    'roles' => array(
      'admin' => 'admin',
      'builder' => 'builder',
      'themer' => 'themer',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view catalyst doctype entities'.
  $permissions['eck view catalyst doctype entities'] = array(
    'name' => 'eck view catalyst doctype entities',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  return $permissions;
}
