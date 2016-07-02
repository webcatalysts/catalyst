<?php

/**
 * @file
 */

class CatalystLayoutMigration extends CatalystEntityMigration {
  protected $entityBundle = 'layout';
  protected function sourceFields() {
    return array(
      'doctype' => t('Doctype'),
      'content' => t('Layout content'),
      'regions' => t('Regions'),
      'debug' => t('Debugging enabled'),
      'css_custom' => t('Custom CSS'),
      'stylesheets' => t('Stylesheet includes'),
      'js_custom' => t('Custom JS'),
      'javascripts' => t('Javascript includes'),
      'files_custom' => t('Custom files'),
      'files_shared' => t('Shared files'),
      'block_placements' => t('Block placements'),
      'block_placement_block_ids' => t('Block placement block ids'),
      'blocks_reference' => t('Referenced blocks'),
      'html_head' => t('Custom HTML Head'),
      'page_title_pattern' => t('Page title pattern'),
      'show_messages' => t('Show messages'),
      'drupal_css_options' => t('Drupal CSS Options'),
      'drupal_js_options' => t('Drupal JS Options'),
      'drupal_processing' => t('Drupal processing'),
      'preprocess_php' => t('Preprocessing PHP'),
      'onselect' => t('Layout On Select'),
      'ondeselect' => t('Layout On DeSelect'),
    ) + parent::SourceFields();
  }
  protected function mapFields() {
    parent::mapFields();
    $this->addFieldMapping('field__drupal_processing', 'drupal_processing');
    $this->addFieldMapping('field__layout_drupal_css', 'drupal_css_options'); //->separator(',');
    $this->addFieldMapping('field__layout_drupal_js', 'drupal_js_options'); //->separator(',');
    $this->addFieldMapping('field__layout_page_title_pattern', 'page_title_pattern');
    $this->addFieldMapping('field__layout_show_messages', 'show_messages');
    $this->addFieldMapping('field__debug', 'debug');
    // Regions
    $this->addFieldMapping('field__layout_regions', 'regions');
    $this->addFieldMapping('field__layout_regions:text', NULL);
    // Block placements
    $this->addFieldMapping('field__blockplacements__layout', 'block_placements');
    $this->addReferenceFieldMapping('field__blockplacements__layout:block_id', 'block_placement_block_ids', 'block');
    // File field mappings
    $this->addFileFieldMapping('field__files', 'files_custom');
    // Reference field mappings
    $this->addReferenceFieldMapping('field__doctype', 'doctype', 'doctype');
    $this->addReferenceFieldMapping('field__blocks_related', 'blocks_reference', 'block');
    $this->addReferenceFieldMapping('field__media_stylesheets__layout', 'stylesheets', 'stylesheet');
    $this->addReferenceFieldMapping('field__media_javascripts__layout', 'javascripts', 'javascript');
    $this->addReferenceFieldMapping('field__media_files', 'files_shared', 'file');
    // Formatted field mappings
    $this->addFormattedFieldMapping('field__body', 'content', 'catalyst_html');
    $this->addFormattedFieldMapping('field__css__layout', 'css_custom', 'catalyst_css');
    $this->addFormattedFieldMapping('field__js__layout', 'js_custom', 'catalyst_js');
    $this->addFormattedFieldMapping('field__html_head', 'html_head', 'catalyst_html');
    $this->addFormattedFieldMapping('field__preprocess', 'preprocess_php', 'catalyst_php');
    $this->addFormattedFieldMapping('field__onselect', 'onselect', 'catalyst_js');
    $this->addFormattedFieldMapping('field__ondeselect', 'ondeselect', 'catalyst_js');
  }
}
