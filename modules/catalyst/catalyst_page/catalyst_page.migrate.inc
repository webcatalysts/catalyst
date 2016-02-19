<?php

/**
 * @file
 */

class CatalystPageMigration extends CatalystNodeMigration {
  protected $nodeType = 'cpage';
  protected function sourceFields() {
    return array(
      'layout' => t('Layout'),
      'content' => t('Content'),
      'css_custom' => t('Custom CSS'),
      'css_includes' => t('Stylesheet Includes'),
      'js_custom' => t('Custom JS'),
      'js_includes' => t('Javascript Includes'),
      'files_custom' => t('Custom Files'),
      'files_shared' => t('Shared Files'),
      'block_placements' => t('Block placements'),
      'block_placement_block_ids' => t('Block placement block IDs'),
      'blocks_ref' => t('Block references'),
      'html_head' => t('Custom HTML Head'),
      'preprocess_php' => t('Preprocess PHP'),
    ) + parent::sourceFields();
  }

  protected function mapFields() {
    parent::mapFields();
    // Block Placements
    $this->addFieldMapping('field__blockplacements__layfield', 'block_placements');
    $this->addReferenceFieldMapping('field__blockplacements__layfield:block_id', 'block_placement_block_ids', 'block');
    // File field mapping
    $this->addFileFieldMapping('field__files', 'files_custom');
    // Reference field mappings
    $this->addReferenceFieldMapping('field__layout', 'layout', 'layout');
    $this->addReferenceFieldMapping('field__media_stylesheets__page', 'css_includes', 'stylesheet');
    $this->addReferenceFieldMapping('field__media_javascripts__page', 'js_includes', 'javascript');
    $this->addReferenceFieldMapping('field__media_files', 'files_shared', 'file');
    $this->addReferenceFieldMapping('field__blocks_related', 'blocks_ref', 'block');
    // Formmatted field mappings
    $this->addFormattedFieldMapping('field__body', 'content', 'catalyst_html');
    $this->addFormattedFieldMapping('field__css__page', 'css_custom', 'catalyst_css');
    $this->addFormattedFieldMapping('field__js__page', 'js_custom', 'catalyst_js');
    $this->addFormattedFieldMapping('field__html_head', 'html_head', 'catalyst_html');
    $this->addFormattedFieldMapping('field__preprocess', 'preprocess_php', 'catalyst_php');
    // Unmapped destinations
    $this->addUnmigratedDestinations(array(
      'promote', 'sticky',
    ));
  }
}
