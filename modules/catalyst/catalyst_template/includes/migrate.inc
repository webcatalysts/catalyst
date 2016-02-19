<?php

/**
 * @file
 */

/**
 * Provides base migration handling for media entities.
 */
class CatalystTemplateMigration extends CatalystEntityMigration {
  protected $entityBundle = 'template';
  protected function sourceFields() {
    return array(
      'files_custom' => t('Custom files'),
      'files_shared' => t('Shared files'),
    ) + parent::sourceFields();
  }

  protected function mapFields() {
    parent::mapFields();
    $this->addFileFieldMapping('field__files', 'files_custom');
    $this->addFormattedFieldMapping('field__body', 'content', 'catalyst_html');
    $this->addReferenceFieldMapping('field__media_files', 'files_shared', 'file');
  }
}
