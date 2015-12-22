<?php

/**
 * @file
 * Menu Lockdown suggestions for the core user module.
 */

/**
 * Implements hook_menu_lockdown_suggestsion().
 */
function user_menu_lockdown_suggestions() {
  return array(
    MENU_LOCKDOWN_BLACKLIST => array(
      'admin/people/permissions*',
      'admin/config/people',
      'admin/config/people/*',
    ),
  );
}
