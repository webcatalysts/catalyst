<?php

/**
 * @file
 * Catalyst import functions.
 */

function catalyst_process_import($migrations) {
  foreach (array_keys($migrations) AS $instance) {
    migrate_static_registration(array($instance));
    $migration = Migration::getInstance($instance);
    $migration->processImport();
  }
}

function catalyst_process_rollback_import($migrations) {
  foreach (array_keys($migrations) AS $instance) {
    //migrate_static_registration(array($instance));
    $migration = Migration::getInstance($instance);
    $migration->processRollback();
  }
}

function catalyst_rollback_import($path, $deregister = TRUE) {
  $info = catalyst_load_import($path);
  catalyst_process_rollback_import($info['migrations']);

  if ($deregister) {
    catalyst_deregister_import($info);
  }
}

function catalyst_load_import($path, $filename = 'catalyst.json') {
  $info = drupal_json_decode(file_get_contents($path . '/' . $filename));
  foreach ($info['migrations'] AS &$migration) {
    $migration['source_directory'] = $path;
  }
  return $info;
}

function catalyst_register_import($info) {
  if (isset($info['groups']) && is_array($info['groups'])) {
    foreach ($info['groups'] as $name => $arguments) {
      $title = $arguments['title'];
      unset($arguments['title']);
      MigrateGroup::register($name, $title, $arguments);
    }
  }
  // Register any migrations defined via the hook.
  if (isset($info['migrations']) && is_array($info['migrations'])) {
    foreach ($info['migrations'] as $machine_name => $arguments) {
      $class_name = $arguments['class_name'];
      unset($arguments['class_name']);
      // Call the right registerMigration implementation. Note that this means
      // that classes that override registerMigration() must always call it
      // directly, they cannot register those classes by defining them in
      // hook_migrate_api() and expect their extension to be called.
      if (is_subclass_of($class_name, 'Migration')) {
        Migration::registerMigration($class_name, $machine_name, $arguments);
      }
      else {
        MigrationBase::registerMigration($class_name, $machine_name, $arguments);
      }
    }
  }
}

function catalyst_deregister_import($info) {
  // Register any migrations defined via the hook.
  if (isset($info['migrations']) && is_array($info['migrations'])) {
    foreach ($info['migrations'] as $machine_name => $arguments) {
      if (is_subclass_of($class_name, 'Migration')) {
        Migration::deregisterMigration($machine_name);
      }
      else {
        MigrationBase::deregisterMigration($machine_name);
      }
    }
  }
  if (isset($info['groups']) && is_array($info['groups'])) {
    foreach (array_keys($info['groups']) as $name) {
      MigrateGroup::deregister($name);
    }
  }
}

/**
 * Might need to extend this to support batching..
 */
function catalyst_import($source_directory) {
  $info = catalyst_load_import($source_directory);
  catalyst_register_import($info);
  catalyst_process_import($info['migrations']);
}
