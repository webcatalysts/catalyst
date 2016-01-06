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
      'css_includes' => t('Stylesheet includes'),
      'js_custom' => t('Custom JS'),
      'js_includes' => t('Javascript includes'),
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
    $this->addFieldMapping('field_catalyst_drupal_processing', 'drupal_processing');
    $this->addFieldMapping('field_layout_drupal_css', 'drupal_css_options'); //->separator(',');
    $this->addFieldMapping('field_layout_drupal_js', 'drupal_js_options'); //->separator(',');
    $this->addFieldMapping('field_layout_page_title_pattern', 'page_title_pattern');
    $this->addFieldMapping('field_layout_show_messages', 'show_messages');
    $this->addFieldMapping('field_layout_debug', 'debug');
    // Regions
    $this->addFieldMapping('field_layout_regions', 'regions');
    $this->addFieldMapping('field_layout_regions:text', NULL);
    // Block placements
    $this->addFieldMapping('field_layout_blocks', 'block_placements');
    $this->addReferenceFieldMapping('field_layout_blocks:block_id', 'block_placement_block_ids', 'block');
    // File field mappings
    $this->addFileFieldMapping('field_catalyst_custom_files', 'files_custom');
    // Reference field mappings
    $this->addReferenceFieldMapping('field_layout_doctype', 'doctype', 'doctype');
    $this->addReferenceFieldMapping('field_catalyst_blocks_add', 'blocks_reference', 'block');
    $this->addReferenceFieldMapping('field_layout_includes_css', 'css_includes', 'stylesheet');
    $this->addReferenceFieldMapping('field_layout_includes_js', 'js_includes', 'javascript');
    $this->addReferenceFieldMapping('field_catalyst_shared_files', 'files_shared', 'file');
    // Formatted field mappings
    $this->addFormattedFieldMapping('field_layout_content', 'content', 'layout_html');
    $this->addFormattedFieldMapping('field_layout_css', 'css_custom', 'css');
    $this->addFormattedFieldMapping('field_layout_js', 'js_custom', 'js');
    $this->addFormattedFieldMapping('field_layout_html_head', 'html_head', 'cpage_html');
    $this->addFormattedFieldMapping('field_layout_preprocess', 'preprocess_php', 'php');
    $this->addFormattedFieldMapping('field_layout_onselect', 'onselect', 'js');
    $this->addFormattedFieldMapping('field_layout_ondeselect', 'ondeselect', 'js');
  }
}
