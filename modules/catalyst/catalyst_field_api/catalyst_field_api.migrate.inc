<?php

/**
 * @file
 */

/**
 * Implements hook_migrate_api().
 */
function catalyst_field_api_migrate_api() {
  return array(
    'api' => 2,
    'field handlers' => array(
      'MigrateBlockPlacementBlockFieldHandler',
      'MigrateBlockPlacementLayoutFieldHandler',
    ),
  );
}

