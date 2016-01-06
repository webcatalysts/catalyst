<?php

/**
 * @file
 */

/**
 * Provides base migration handling for media entities.
 */
abstract class CatalystMediaMigration extends CatalystEntityMigration {
  use CatalystEntityMachineNamePrepare;

  protected $machineField = 'field__machine';
  protected $machineKey = 'machine_name';

  protected function sourceFields() {
    return array(
      'machine_name' => t('Machine name'),
      'media_type' => t('Media Type'),
      'media_path' => t('Media Path'),
    ) + parent::sourceFields();
  }

  protected function mapFields() {
    parent::mapFields();
    $this->addFieldMapping('field__machine', 'machine_name');
    $this->addFieldMapping('field__media_type', 'media_type');
    $this->addFieldMapping('field__media_path', 'media_path');
  }
}

class CatalystMediaStylesheetMigration extends CatalystMediaMigration {
  protected $entityBundle = 'stylesheet';
  protected function sourceFields() {
    return array(
      'content' => t('Content'),
      'media' => t('Media'),
      'files_custom' => t('Custom files'),
      'files_shared' => t('Shared files'),
    ) + parent::sourceFields();
  }
  protected function mapFields() {
    parent::mapFields();
    $this->addFieldMapping('field__media_stylesheet_media', 'media');
    $this->addFormattedFieldMapping('field__body', 'content', 'css');
    $this->addReferenceFieldMapping('field__media_files', 'files_shared', 'file');
    $this->addFileFieldMapping('field__files', 'files_custom');
  }
}

class CatalystMediaJavascriptMigration extends CatalystMediaMigration {
  protected $entityBundle = 'javascript';
  protected function sourceFields() {
    return array(
      'content' => t('Content'),
      'defer' => t('Defer'),
      'scope' => t('Scope'),
    ) + parent::sourceFields();
  }
  protected function mapFields() {
    parent::mapFields();
    $this->addFieldMapping('field__media_javascript_defer', 'defer');
    $this->addFieldMapping('field__media_javascript_scope', 'scope');
    $this->addFormattedFieldMapping('field__body', 'content', 'js');
  }
}

class CatalystMediaFileMigration extends CatalystMediaMigration {
  protected $entityBundle = 'file';
  protected function sourceFields() {
    return array(
      'file_path' => t('File path'),
    ) + parent::sourceFields();
  }
  protected function mapFields() {
    parent::mapFields();
    $this->addFileFieldMapping('field__media_file', 'file_path');
  }
}
