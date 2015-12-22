<?php

/**
 * @file
 * Menu Lockdown suggestions for the core taxonomy module.
 */

/**
 * Implements hook_menu_lockdown_suggestions().
 */
function taxonomy_menu_lockdown_suggestions() {
  return array(
    MENU_LOCKDOWN_BLACKLIST => array(
      'admin/structure/taxonomy/add',
      'admin/structure/taxonomy/%taxonomy_vocabulary_machine_name/edit',
    ),
  );
}
