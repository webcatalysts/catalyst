<?php
/**
 * @file
 * catalyst_core.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function catalyst_core_user_default_roles() {
  $roles = array();

  // Exported role: catalyst admin.
  $roles['catalyst admin'] = array(
    'name' => 'catalyst admin',
    'weight' => 6,
  );

  // Exported role: catalyst builder.
  $roles['catalyst builder'] = array(
    'name' => 'catalyst builder',
    'weight' => 4,
  );

  // Exported role: catalyst editor.
  $roles['catalyst editor'] = array(
    'name' => 'catalyst editor',
    'weight' => 2,
  );

  // Exported role: catalyst themer.
  $roles['catalyst themer'] = array(
    'name' => 'catalyst themer',
    'weight' => 3,
  );

  // Exported role: catalyst uadmin.
  $roles['catalyst uadmin'] = array(
    'name' => 'catalyst uadmin',
    'weight' => 5,
  );

  return $roles;
}
