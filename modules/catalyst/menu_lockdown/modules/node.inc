<?php

/**
 * @file
 * Menu Lockdown suggestions for the core node module.
 */

/**
 * Implements hook_menu_lockdown_suggestions().
 */
function node_menu_lockdown_suggestions() {
  return array(
    MENU_LOCKDOWN_BLACKLIST => array(
      'admin/structure/types',
      'admin/structure/types/*',
    ),
  );
}
