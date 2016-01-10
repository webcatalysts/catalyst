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

  // Exported role: admin.
  $roles['admin'] = array(
    'name' => 'admin',
    'weight' => 6,
  );

  // Exported role: builder.
  $roles['builder'] = array(
    'name' => 'builder',
    'weight' => 4,
  );

  // Exported role: editor.
  $roles['editor'] = array(
    'name' => 'editor',
    'weight' => 2,
  );

  // Exported role: themer.
  $roles['themer'] = array(
    'name' => 'themer',
    'weight' => 3,
  );

  // Exported role: uadmin.
  $roles['uadmin'] = array(
    'name' => 'uadmin',
    'weight' => 5,
  );

  return $roles;
}
