<?php
/**
 * @file
 * catalyst_page.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function catalyst_page_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create cpage content'.
  $permissions['create cpage content'] = array(
    'name' => 'create cpage content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete any cpage content'.
  $permissions['delete any cpage content'] = array(
    'name' => 'delete any cpage content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'delete own cpage content'.
  $permissions['delete own cpage content'] = array(
    'name' => 'delete own cpage content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit any cpage content'.
  $permissions['edit any cpage content'] = array(
    'name' => 'edit any cpage content',
    'roles' => array(),
    'module' => 'node',
  );

  // Exported permission: 'edit own cpage content'.
  $permissions['edit own cpage content'] = array(
    'name' => 'edit own cpage content',
    'roles' => array(),
    'module' => 'node',
  );

  return $permissions;
}
