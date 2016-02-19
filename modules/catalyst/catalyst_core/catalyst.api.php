<?php

/**
 * @file
 * Hooks provided by Catalyst (core).
 */

/**
 * Provide one or more catalyst export groups.
 */
function hook_catalyst_info() {
  return array(
    'mygroup' => array(
      'title' => t('My Group Title'),
      'prepare callback' => 'mygroup_prepare_export',
      'export callback' => 'catalyst_export_json_encode',
      'export options' => array(),
      'export type' => 'json',
      'migration' => array(
        'class_name' => 'MyGroupMigration',
      ),
      'migration sources' => array('anothergroup'),
    ),
  );
}

function hook_catalyst_export_alter(object $export, object $original, array $group) {}
function hook_catalyst_candidates(array $group) {}
function hook_catalyst_dependencies(object $export, array $group) {}
function hook_catalyst_prepare_export(object $export, array $group, array $exports) {}

function hook_catalyst_ignore_menus() {}
function hook_catalyst_ignore_menus_alter(&$ignore_menus) {}
