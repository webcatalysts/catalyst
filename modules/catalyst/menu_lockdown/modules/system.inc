<?php

/**
 * @file
 * Menu Lockdown suggestions for the core system module.
 */

/**
 * Implements hook_menu_lockdown_suggestions().
 */
function system_menu_lockdown_suggestions() {
  return array(
    MENU_LOCKDOWN_BLACKLIST => array(
      'admin/appearance*',
      'admin/modules*',
      'admin/config/search/clean-urls',
    ),
  );
}
