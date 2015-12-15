<?php

/**
 * @file
 * better_migrate_example.migrate.inc
 */

/**
 * Implements hook_migrate_api().
 */
function better_migrate_example_migrate_api() {
  return array(
    'api' => 2,
    'migrations' => array(
      'EveryField' => array(
        'class_name' => 'EveryFieldMigration',
      ),
      'TestEveryField' => array(
        'class_name' => 'TestEveryFieldMigration',
      ),
    ),
  );
}
