<?php

/**
 * @file
 */

class CatalystBlockMigration extends CatalystEntityMigration {
  protected $entityBundle = 'block';

  protected function sourceFields() {
    return array(
      'content' => t('Block content'),
      'css_custom' => t('Custom CSS'),
      'stylesheets' => t('CSS Includes'),
      'js_custom' => t('Custom JS'),
      'javascripts' => t('JS Includes'),
      'files_custom' => t('Custom Files'),
      'files_shared' => t('Shared Files'),
      'preprocess_php' => t('Preprocess PHP'),
      'block_placements' => t('Block placements'),
      'block_placement_ids' => t('Block placement layout IDs'),
    ) + parent::sourceFields();
  }
  //*/

  protected function mapFields() {
    parent::mapFields();
    // Block placements
    if ($this->hasSourceMigration('layout')) {
      $this->addFieldMapping('field__blockplacements__block', 'block_placements');
      $this->addReferenceFieldMapping('field__blockplacements__block:layout_id', 'block_placement_ids', 'layout');
    }
    // Reference field mapping
    $this->addReferenceFieldMapping('field__media_stylesheets', 'stylesheets', 'stylesheet');
    $this->addReferenceFieldMapping('field__media_javascripts', 'javascripts', 'javascript');
    $this->addReferenceFieldMapping('field__media_files', 'files_shared', 'file');
    // Mappings for formatted fields
    $this->addFormattedFieldMapping('field__body', 'content', 'catalyst_html');
    $this->addFormattedFieldMapping('field__preprocess', 'preprocess_php', 'catalyst_php');
    $this->addFormattedFieldMapping('field__css', 'css_custom', 'catalyst_css');
    $this->addFormattedFieldMapping('field__js', 'js_custom', 'catalyst_js');
    // File field mapping
    $this->addFileFieldMapping('field__files', 'files_custom');
  }
}
