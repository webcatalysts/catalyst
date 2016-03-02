<?php

/**
 * @file
 *
 * Package related functions and callbacks for Catalyst.
 */

class CatalystPackageMigration extends CatalystEntityMigration {
  protected $entityBundle = 'package';

  protected function sourceFields() {
    return array(
      'content' => t('Description'),
      'internal' => t('Internal'),
      'machine_name' => t('Machine name'),
    ) + parent::sourceFields();
  }

  protected function mapFields() {
    parent::mapFields();
    $this->addFieldMapping('field__body', 'content');
  }
}
