<?php

/**
 * @file
 */

/**
 * Provides basic field mapping that applies to all Catalyst entity migrations.
 *
 * Used to determine how global properties are handled.
 */
abstract class CatalystBaseMigration extends BetterMigration {
  use CatalystMigrationCommonMappings;

  /**
   * Get a source migration name.
   *
   * Allows for dynamic source migration names.
   */
  protected function getSourceMigration($key) {
    // Checkout dependancies first
    if ($migration_name = $this->getDependency($key)) {
      return $migration_name;
    }
    // Allow source migrations to be passed as arguments as the migration
    // because the migration names are dynamic
    if (isset($this->arguments['source_migrations'][$key])) {
      return $this->arguments['source_migrations'][$key];
    }
    return $key;
  }

  protected function getSourceFilesDirectory() {
    if (isset($this->arguments['source_files_directory'])) {
      return $this->getSourceDirectory() . '/' . $this->arguments['source_files_directory'];
    }
    return $this->getSourceDirectory();
  }

  /**
   * Allow extending migrations to customize stub titles by override this
   * method.
   */
  protected function createStubTitle(Migration $migration, array $source_id) {
    return t('Stub for @source_id', array('@source_id' => $source_id[0]));
  }
}
abstract class CatalystMigration extends CatalystBaseMigration {
  use BetterMigrateSourceJSON;
  use BetterMigrateMapSQLSimpleInteger;

  public function prepareRow($row) {
    parent::prepareRow($row);
    $row = (object)json_decode(json_encode($row), true);
    $row->json_decoded = TRUE;
    return TRUE;
  }

  protected function sourceFields() {
    return array(
      'id' => t('ID'),
      'title' => t('Title'),
    );
  }

  protected function mapFields() {
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('language')->defaultValue(LANGUAGE_NONE);
    $this->addUnmigratedDestinations(array('created', 'changed'));
  }
}

abstract class CatalystEntityMigration extends CatalystMigration {
  use CatalystEntityMachineNamePrepare;
  use BetterMigrationDestinationEntity;
  protected $entityType = 'catalyst';
  protected $machineField = 'field__machine';
  protected $machineKey = 'machine';
  protected $sourceIDField = 'id';

  protected function sourceFields() {
    return array(
      'machine' => t('Machine name'),
    ) + parent::sourceFields();
  }

  protected function mapFields() {
    $this->addFieldMapping('title', 'title');

  protected function mapFields() {
    parent::mapFields();
    $this->addFieldMapping('type')->defaultValue($this->entityBundle);
    $this->addUnmigratedDestinations(array('id', 'path', 'pathauto'));
  }

  protected function createStub(Migration $migration, array $source_id) {
    $entity = entity_create($this->entityType, array('type' => $this->entityBundle));
    $wrapper = entity_metadata_wrapper($this->entityType, $entity);
    $wrapper->title->set($this->createStubTitle($migration, $source_id));
    $wrapper->save();
    if ($stub_id = $wrapper->getIdentifier()) {
      return array($stub_id);
    }
    return FALSE;
  }
}

abstract class CatalystNodeMigration extends CatalystMigration {
  use CatalystEntityMachineNamePrepare;
  use BetterMigrateSourceJSON;
  use BetterMigrationDestinationNode;
  use BetterMigrateMapSQLSimpleInteger;
  use CatalystMigrationCommonMappings;

  protected $nodeType = 'cpape';

  protected $entityType = 'node';
  protected $machineField = 'field__machine';
  protected $machineKey = 'machine';
  protected $sourceIDField = 'nid';


  protected function sourceFields() {
    return array(
      'status' => t('Status'),
      'path' => t('Path alias'),
      'machine' => t('Machine name'),
    ) + parent::sourceFields();
  }

  protected function mapFields() {
    parent::mapFields();
    $this->addFieldMapping('uid')->defaultValue(1);
    $this->addFieldMapping('status', 'status');
    $this->addFieldMapping('path', 'path');
    $this->addFieldMapping('pathauto')->defaultValue(1);
    $this->addUnmigratedDestinations(array(
      'revision', 'log', 'tnid', 'translate', 'revision_uid', 'is_new', 'comment',
    ));
  }

  protected function createStub(Migration $migration, array $source_ids) {
    $node = entity_create('node', array(
      'type' => $this->nodeType,
      'title' => $this->createStubTitle($migration, $source_ids),
      'uid' => 1
    ));
    node_save($node);
    return isset($node->nid) && $node->nid ? array($node->nid) : FALSE;
  }
}

trait CatalystEntityMachineNamePrepare {
  function prepare($entity, $row) {
    if (isset($entity->is_new) && $entity->is_new) {
      if ($id = machine_lookup_single($this->machineField, $row->{$this->machineKey}, $this->entityType, $this->entityBundle)) {
        $entity->id = $id;
        $entity->is_new = FALSE;
      }
    }
  }
}

trait CatalystMigrationCommonMappings {

  /**
   * Add mappings for a formatted text field.
   *
   * Maps the field and :format subfield.
   */
  protected function addFormattedFieldMapping($field_name, $source_field, $format) {
    $mapping = $this->addFieldMapping($field_name, $source_field)
      ->callbacks('html_entity_decode');
    $this->addFieldMapping($field_name . ':format')
      ->defaultValue($format);
    return $mapping;
  }

  /**
   * Add mappings for a reference field.
   *
   * Resolves and adds the source migration to the mapping.
   * Tested with entity reference.
   */
  protected function addReferenceFieldMapping($field_name, $source_field, $source_migration_key, $dependant = FALSE, $separator = FALSE) {
    if ($source_migration = $this->getSourceMigration($source_migration_key)) {
      $mapping = $this->addFieldMapping($field_name, $source_field);
      $mapping->sourceMigration($source_migration);
      // Using a separator isn't really relevant after converting
      // CatalystMigration(s) to JSON
      if ($separator != FALSE) {
        $mapping->separator($separator);
      }
      return $mapping;
    }
    elseif ($dependant) {
      // trigger error
      return FALSe;
    }
    // When the source migration doesn't exist, this field is unmigrated
    $this->addUnmigratedDestination($field_name);
    $this->addUnmigratedSource($source_field);
    return NULL;
  }

  /**
   * Add file field mappings.
   *
   * Maps the :source_dir and other subfields according to CatalystMigration
   * defaults.
   */
  protected function addFileFieldMapping($field_name, $source_field, $separator = FALSE) {
    $mapping = $this->addFieldMapping($field_name, $source_field);
    // Using a separator isn't really relevant after converting
    // CatalystMigration(s) to JSON
    if ($separator == FALSE) {
      $mapping->separator($separator);
    }
    $this->addFieldMapping($field_name . ':source_dir')
      ->defaultValue($this->getSourceFilesDirectory());
    $this->addFieldMapping($field_name . ':preserve_files')
      ->defaultValue(FALSE);
    $this->addFieldMapping($field_name . ':file_replace')
      ->defaultValue(FILE_EXISTS_REPLACE);
    $this->addUnmigratedDestinations(array(
      $field_name . ':file_class',
      $field_name . ':destination_dir',
      $field_name . ':destination_file',
      $field_name . ':description',
      $field_name . ':urlencode',
      $field_name . ':display',
    ));
    return $mapping;
  }

  /**
   * Add a single simple field mapping.
   */
  protected function addSimpleFieldMapping($field_name) {
    return $this->addFieldMapping($field_name, $field_name);
  }

  /**
   * Add a single unmigrated destination field.
   */
  protected function addUnmigratedDestination($field_name) {
    $this->addUnmigratedDestinations(array($field_name));
  }

  /**
   * Add a single unmigrated source field.
   */
  protected function addUnmigratedSource($source_field) {
    $this->addUnmigratedDestinations(array($source_field));
  }
}
