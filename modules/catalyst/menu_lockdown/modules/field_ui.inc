<?php

/**
 * @file
 * Menu Lockdown suggestsions for the core field_ui module.
 *
 * This module should typically be disabled in production but there are some
 * modules that depend on it.
 */

/**
 * Implements hook_menu_lockdown_suggestions().
 */
function field_ui_menu_lockdown_suggestions() {
  return array(
    MENU_LOCKDOWN_BLACKLIST => array(
      'admin/help/field_ui',
      'admin/reports/fields',
      'admin/structure/taxonomy/%taxonomy_vocabulary_machine_name/fields',
      'admin/structure/taxonomy/%taxonomy_vocabulary_machine_name/fields/*',
      'admin/structure/taxonomy/%taxonomy_vocabulary_machine_name/display',
      'admin/structure/taxonomy/%taxonomy_vocabulary_machine_name/display/*',
    ),
  );
}
