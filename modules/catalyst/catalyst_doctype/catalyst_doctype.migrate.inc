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
    $this->addFieldMapping('field_doctype_charset', 'charset');
    $this->addFieldMapping('field_doctype_content_type', 'http_content_type');
    $this->addFieldMapping('field_catalyst_drupal_processing', 'drupal_processing');
    // Formatted field mappings
    $this->addFormattedFieldMapping('field_doctype_content', 'content', 'layout_html');
    $this->addFormattedFieldMapping('field_doctype_preprocess', 'preprocess_php', 'php');
    $this->addFormattedFieldMapping('field_doctype_onselect', 'onselect', 'javascript');
    $this->addFormattedFieldMapping('field_doctype_ondeselect', 'ondeselect', 'javascript');
  }
}
