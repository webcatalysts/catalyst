<?php

/**
 * @file
 */

class CatalystDoctypeMigration extends CatalystEntityMigration {
  protected $entityBundle = 'doctype';
  protected function sourceFields() {
    return array(
      'content' => t('Content'),
      'charset' => t('Character set'),
      'http_content_type' => t('Content type'),
      'drupal_processing' => t('Drupal processing enabled'),
      'preprocess_php' => t('Preprocessing PHP'),
      'onselect' => t('OnSelect'),
      'ondeselect' => t('OnDeselect'),
    ) + parent::sourceFields();
  }
  protected function mapFields() {
    parent::mapFields();
    $this->addFieldMapping('field__doctype_charset', 'charset');
    $this->addFieldMapping('field__doctype_content_type', 'http_content_type');
    $this->addFieldMapping('field__drupal_processing', 'drupal_processing');
    // Formatted field mappings
    $this->addFormattedFieldMapping('field__body', 'content', 'catalyst_html');
    $this->addFormattedFieldMapping('field__preprocess', 'preprocess_php', 'catalyst_php');
    $this->addFormattedFieldMapping('field__onselect', 'onselect', 'catalyst_js');
    $this->addFormattedFieldMapping('field__ondeselect', 'ondeselect', 'catalyst_js');
  }
}
