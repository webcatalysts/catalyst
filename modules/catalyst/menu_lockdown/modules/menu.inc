<?php

/**
 * @file
 * Menu Lockdown suggestions for the core menu module.
 */

/**
 * Implements hook_menu_lockdown_suggestions().
 */
function menu_menu_lockdown_suggestions() {
  return array(
    MENU_LOCKDOWN_BLACKLIST => array(
      'admin/structure/menu/add',
      'admin/structure/menu/settings',
      'admin/structure/menu/manage/%menu/edit',
      'admin/structure/menu/manage/%menu/delete',
    ),
  );
}
