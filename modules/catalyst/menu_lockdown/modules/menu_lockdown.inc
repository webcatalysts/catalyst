<?php

/**
 * @file
 * Menu Lockdown suggestions for the menu_lockdown module itself.
 */

/**
 * Implements hook_menu_lockdown_suggestions().
 */
function menu_lockdown_menu_lockdown_suggestions() {
  return array(
    MENU_LOCKDOWN_BLACKLIST => array(
      'admin/config/development/menu-lockdown/*',
    ),
    MENU_LOCKDOWN_WHITELIST => array(
      'admin/config/development/menu-lockdown/debug',
    ),
  );
}


