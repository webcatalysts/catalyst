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
    'roles' => array(
      'catalyst admin' => 'catalyst admin',
      'catalyst builder' => 'catalyst builder',
      'catalyst editor' => 'catalyst editor',
      'catalyst themer' => 'catalyst themer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any cpage content'.
  $permissions['delete any cpage content'] = array(
    'name' => 'delete any cpage content',
    'roles' => array(
      'catalyst admin' => 'catalyst admin',
      'catalyst builder' => 'catalyst builder',
      'catalyst editor' => 'catalyst editor',
      'catalyst themer' => 'catalyst themer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own cpage content'.
  $permissions['delete own cpage content'] = array(
    'name' => 'delete own cpage content',
    'roles' => array(
      'catalyst admin' => 'catalyst admin',
      'catalyst builder' => 'catalyst builder',
      'catalyst editor' => 'catalyst editor',
      'catalyst themer' => 'catalyst themer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any cpage content'.
  $permissions['edit any cpage content'] = array(
    'name' => 'edit any cpage content',
    'roles' => array(
      'catalyst admin' => 'catalyst admin',
      'catalyst builder' => 'catalyst builder',
      'catalyst editor' => 'catalyst editor',
      'catalyst themer' => 'catalyst themer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own cpage content'.
  $permissions['edit own cpage content'] = array(
    'name' => 'edit own cpage content',
    'roles' => array(
      'catalyst admin' => 'catalyst admin',
      'catalyst builder' => 'catalyst builder',
      'catalyst editor' => 'catalyst editor',
      'catalyst themer' => 'catalyst themer',
    ),
    'module' => 'node',
  );

  // Exported permission: 'enter cpage revision log entry'.
  $permissions['enter cpage revision log entry'] = array(
    'name' => 'enter cpage revision log entry',
    'roles' => array(
      'catalyst admin' => 'catalyst admin',
      'catalyst builder' => 'catalyst builder',
      'catalyst editor' => 'catalyst editor',
      'catalyst themer' => 'catalyst themer',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override cpage authored by option'.
  $permissions['override cpage authored by option'] = array(
    'name' => 'override cpage authored by option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override cpage authored on option'.
  $permissions['override cpage authored on option'] = array(
    'name' => 'override cpage authored on option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override cpage promote to front page option'.
  $permissions['override cpage promote to front page option'] = array(
    'name' => 'override cpage promote to front page option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override cpage published option'.
  $permissions['override cpage published option'] = array(
    'name' => 'override cpage published option',
    'roles' => array(
      'catalyst admin' => 'catalyst admin',
      'catalyst builder' => 'catalyst builder',
      'catalyst editor' => 'catalyst editor',
      'catalyst themer' => 'catalyst themer',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override cpage revision option'.
  $permissions['override cpage revision option'] = array(
    'name' => 'override cpage revision option',
    'roles' => array(
      'catalyst admin' => 'catalyst admin',
      'catalyst builder' => 'catalyst builder',
      'catalyst editor' => 'catalyst editor',
      'catalyst themer' => 'catalyst themer',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override cpage sticky option'.
  $permissions['override cpage sticky option'] = array(
    'name' => 'override cpage sticky option',
    'roles' => array(),
    'module' => 'override_node_options',
  );

  return $permissions;
}
