<?php

/**
 * @file
 * Menu lockdown suggestions for the core filter module.
 */

/**
 * Implements hook_menu_lockdown_suggestions().
 */
function filter_menu_lockdown_suggestions() {
  return array(
    'blacklist' => array(
      'admin/config/content/formats*',
    ),
  );
}

