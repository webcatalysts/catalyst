<?php

/**
 * @file
 * Menu Lockdown suggestions for the core shortcut module.
 */

/**
 * Implements hook_menu_lockdown_suggestions().
 */
function shortcut_menu_lockdown_suggestions() {
  return array(
    MENU_LOCKDOWN_WHITELIST => array(
      'admin/config/user-interface',
      'admin/config/user-interface/shortcut',
      'admin/config/user-interface/shortcut/*',
    ),
  );
}
