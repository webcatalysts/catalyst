<?php

/**
 * @file
 */

class CatalystTemplateMigration extends CatalystLayoutMigration {
  protected $entityBundle = 'template';
  protected function sourceFields() {
    return array(
      'entity_type' => t('Entity Type'),
      'bundle' => t('Bundle'),
    ) + parent::SourceFields();
  }
  protected function mapFields() {
    parent::mapFields();
    $this->addFieldMapping('field__template_entity_type', 'entity_type');
    $this->addFieldMapping('field__template_bundle', 'bundle');
  }
}
