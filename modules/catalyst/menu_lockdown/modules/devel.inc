<?php

/**
 * @file
 * Menu Lockdown suggestions for the devel module.
 */

/**
 * Implements hook_menu_lockdown_suggestions().
 */
function devel_menu_lockdown_suggestions() {
  return array(
    MENU_LOCKDOWN_BLACKLIST => array(
      'devel/*',
      'admin/config/development/devel',
      'node/%node/devel',
      'node/%node/devel/*',
      'comment/%comment/devel',
      'comment/%comment/devel/*',
      'user/%user/devel',
      'user/%user/devel/*',
      'taxonomy/term/%taxonomy_term/devel',
      'taxonomy/term/%taxonomy_term/devel/*',
    ),
    MENU_LOCKDOWN_WHITELIST => array(
      'devel/cache/clear',
    ),
  );
}

