<?php

/**
 * @file
 */

/**
 * Provides basic field mapping that applies to all Catalyst entity migrations.
 *
 * Used to determine how global properties are handled.
 */

abstract class CatalystMigration extends BetterMigration {
  use BetterMigrationSourceXML;
  use BetterMigrationMapSQLSimple;
  use CatalystMigrationCommonMappings;
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
  use BetterMigrationDestinationEntity;
  protected $entityType = 'catalyst';
  protected function mapFields() {
    parent::mapFields();
    $this->addFieldMapping('type')->defaultValue($this->entityBundle);
    $this->addUnmigratedDestinations(array('id', 'path', 'pathauto'));
  }
}

abstract class CatalystNodeMigration extends CatalystMigration {
  use BetterMigrationSourceXML;
  use BetterMigrationDestinationNode;
  use BetterMigrationMapSQLSimple;
  use CatalystMigrationCommonMappings;

  protected function sourceFields() {
    return array(
      'status' => t('Status'),
      'path' => t('Path alias'),
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
  protected function addFormattedFieldMapping($field_name, $source_field, $format) {
    $this->addFieldMapping($field_name, $source_field)
      ->callbacks('html_entity_decode');
    $this->addFieldMapping($field_name . ':format')
      ->defaultValue($format);
  }

  protected function addReferenceFieldMapping($field_name, $source_field, $dependency, $separator = ',') {
    $mapping =$this->addFieldMapping($field_name, $source_field);
    $mapping->sourceMigration($this->getDependency($dependency));
    if ($separator != FALSE) {
      $mapping->separator($separator);
    }
  }

  protected function addFileFieldMapping($field_name, $source_field, $separator = '|') {
    if ($separator == FALSE) {
      $this->addFieldMapping($field_name, $source_field);
    }
    else {
      $this->addFieldMapping($field_name, $source_field)
        ->separator('|');
    }
    $this->addFieldMapping($field_name . ':source_dir')
      ->defaultValue($this->getDataDirectory());
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
  }
}
