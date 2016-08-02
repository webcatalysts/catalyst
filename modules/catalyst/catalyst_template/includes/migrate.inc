<?php

/**
 * @file
 */

class CatalystTemplateMigration extends CatalystEntityMigration {
  protected $entityBundle = 'template';
  protected function sourceFields() {
    return array(
      'entity_type' => t('Entity type'),
      'bundle' => t('Bundle'),
      'block_placements' => t('Block placements'),
      'block_placement_ids' => t('Block placement block ids'),
      'blocks_reference' => t('Referenced blocks'),
      'layout' => t('Doctype'),
      'content' => t('Layout content'),
      'debug' => t('Debugging enabled'),
      'css_custom' => t('Custom CSS'),
      'stylesheets' => t('Stylesheet includes'),
      'js_custom' => t('Custom JS'),
      'javascripts' => t('Javascript includes'),
      'files_custom' => t('Custom files'),
      'files_shared' => t('Shared files'),
      'html_head' => t('Custom HTML Head'),
      'preprocess_php' => t('Preprocessing PHP'),
    ) + parent::SourceFields();
  }
  protected function mapFields() {
    parent::mapFields();
    $this->addFieldMapping('field__template_entity_type', 'entity_type');
    $this->addFieldMapping('field__template_bundle', 'bundle');
    $this->addFieldMapping('field__layout', 'layout');

    $this->addFieldMapping('field__debug', 'debug');
    // Block placements
    $this->addFieldMapping('field__blockplacements__layfield', 'block_placements');
    $this->addReferenceFieldMapping('field__blockplacements__layfield:block_id', 'block_placement_ids', 'block');
    // File field mappings
    $this->addFileFieldMapping('field__files', 'files_custom');
    // Reference field mappings
    $this->addReferenceFieldMapping('field__blocks_related', 'blocks_reference', 'block');
    $this->addReferenceFieldMapping('field__media_stylesheets__page', 'stylesheets', 'stylesheet');
    $this->addReferenceFieldMapping('field__media_javascripts__page', 'javascripts', 'javascript');
    $this->addReferenceFieldMapping('field__media_files', 'files_shared', 'file');
    // Formatted field mappings
    $this->addFormattedFieldMapping('field__body', 'content', 'catalyst_html');
    $this->addFormattedFieldMapping('field__css__page', 'css_custom', 'catalyst_css');
    $this->addFormattedFieldMapping('field__js__page', 'js_custom', 'catalyst_js');
    $this->addFormattedFieldMapping('field__html_head', 'html_head', 'catalyst_html');
    $this->addFormattedFieldMapping('field__preprocess', 'preprocess_php', 'catalyst_php');
  }
}
