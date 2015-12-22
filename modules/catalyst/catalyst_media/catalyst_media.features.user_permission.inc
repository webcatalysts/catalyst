<?php
/**
 * @file
 * catalyst_media.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function catalyst_media_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'eck add catalyst file entities'.
  $permissions['eck add catalyst file entities'] = array(
    'name' => 'eck add catalyst file entities',
    'roles' => array(
      'admin' => 'admin',
      'builder' => 'builder',
      'editor' => 'editor',
      'themer' => 'themer',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add catalyst javascript entities'.
  $permissions['eck add catalyst javascript entities'] = array(
    'name' => 'eck add catalyst javascript entities',
    'roles' => array(
      'admin' => 'admin',
      'builder' => 'builder',
      'themer' => 'themer',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck add catalyst stylesheet entities'.
  $permissions['eck add catalyst stylesheet entities'] = array(
    'name' => 'eck add catalyst stylesheet entities',
    'roles' => array(
      'admin' => 'admin',
      'builder' => 'builder',
      'themer' => 'themer',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer catalyst file entities'.
  $permissions['eck administer catalyst file entities'] = array(
    'name' => 'eck administer catalyst file entities',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer catalyst javascript entities'.
  $permissions['eck administer catalyst javascript entities'] = array(
    'name' => 'eck administer catalyst javascript entities',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck administer catalyst stylesheet entities'.
  $permissions['eck administer catalyst stylesheet entities'] = array(
    'name' => 'eck administer catalyst stylesheet entities',
    'roles' => array(
      'admin' => 'admin',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete catalyst file entities'.
  $permissions['eck delete catalyst file entities'] = array(
    'name' => 'eck delete catalyst file entities',
    'roles' => array(
      'admin' => 'admin',
      'builder' => 'builder',
      'editor' => 'editor',
      'themer' => 'themer',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete catalyst javascript entities'.
  $permissions['eck delete catalyst javascript entities'] = array(
    'name' => 'eck delete catalyst javascript entities',
    'roles' => array(
      'admin' => 'admin',
      'builder' => 'builder',
      'themer' => 'themer',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck delete catalyst stylesheet entities'.
  $permissions['eck delete catalyst stylesheet entities'] = array(
    'name' => 'eck delete catalyst stylesheet entities',
    'roles' => array(
      'admin' => 'admin',
      'builder' => 'builder',
      'themer' => 'themer',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit catalyst file entities'.
  $permissions['eck edit catalyst file entities'] = array(
    'name' => 'eck edit catalyst file entities',
    'roles' => array(
      'admin' => 'admin',
      'builder' => 'builder',
      'editor' => 'editor',
      'themer' => 'themer',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit catalyst javascript entities'.
  $permissions['eck edit catalyst javascript entities'] = array(
    'name' => 'eck edit catalyst javascript entities',
    'roles' => array(
      'admin' => 'admin',
      'builder' => 'builder',
      'themer' => 'themer',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck edit catalyst stylesheet entities'.
  $permissions['eck edit catalyst stylesheet entities'] = array(
    'name' => 'eck edit catalyst stylesheet entities',
    'roles' => array(
      'admin' => 'admin',
      'builder' => 'builder',
      'themer' => 'themer',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list catalyst file entities'.
  $permissions['eck list catalyst file entities'] = array(
    'name' => 'eck list catalyst file entities',
    'roles' => array(
      'admin' => 'admin',
      'builder' => 'builder',
      'editor' => 'editor',
      'themer' => 'themer',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list catalyst javascript entities'.
  $permissions['eck list catalyst javascript entities'] = array(
    'name' => 'eck list catalyst javascript entities',
    'roles' => array(
      'admin' => 'admin',
      'builder' => 'builder',
      'themer' => 'themer',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck list catalyst stylesheet entities'.
  $permissions['eck list catalyst stylesheet entities'] = array(
    'name' => 'eck list catalyst stylesheet entities',
    'roles' => array(
      'admin' => 'admin',
      'builder' => 'builder',
      'themer' => 'themer',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view catalyst file entities'.
  $permissions['eck view catalyst file entities'] = array(
    'name' => 'eck view catalyst file entities',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view catalyst javascript entities'.
  $permissions['eck view catalyst javascript entities'] = array(
    'name' => 'eck view catalyst javascript entities',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'eck view catalyst stylesheet entities'.
  $permissions['eck view catalyst stylesheet entities'] = array(
    'name' => 'eck view catalyst stylesheet entities',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'eck',
  );

  // Exported permission: 'use text format css'.
  $permissions['use text format css'] = array(
    'name' => 'use text format css',
    'roles' => array(
      'admin' => 'admin',
      'builder' => 'builder',
      'themer' => 'themer',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'use text format js'.
  $permissions['use text format js'] = array(
    'name' => 'use text format js',
    'roles' => array(
      'admin' => 'admin',
      'builder' => 'builder',
      'themer' => 'themer',
    ),
    'module' => 'filter',
  );

  return $permissions;
}
