<?php

/**
 * @file
 */

class CatalystBlockMigration extends CatalystEntityMigration {
  use CatalystEntityMachineNamePrepare;

  protected $entityBundle = 'block';
  protected $machineField = 'field_block_machine';
  protected $machineKey = 'machine_name';

  protected function sourceFields() {
    return array(
      'machine_name' => t('Machine name'),
      'content' => t('Block content'),
      'css_custom' => t('Custom CSS'),
      'css_includes' => t('CSS Includes'),
      'js_custom' => t('Custom JS'),
      'js_includes' => t('JS Includes'),
      'files_custom' => t('Custom Files'),
      'files_shared' => t('Shared Files'),
      'preprocess_php' => t('Preprocess PHP'),
    ) + parent::sourceFields();
  }

  protected function mapFields() {
    parent::mapFields();
    $this->addFieldMapping('field_block_machine', 'machine_name');
    // Reference field mapping
    $this->addReferenceFieldMapping('field_catalyst_includes_css', 'css_includes', 'stylesheet', ',');
    $this->addReferenceFieldMapping('field_catalyst_includes_js', 'js_includes', 'javascript', ',');
    $this->addReferenceFieldMapping('field_catalyst_shared_files', 'files_shared', 'file', ',');
    // Mappings for formatted fields
    $this->addFormattedFieldMapping('field_block_content', 'content', 'page_html');
    $this->addFormattedFieldMapping('field_block_preprocess', 'preprocess_php', 'php');
    $this->addFormattedFieldMapping('field_catalyst_custom_css', 'css_custom', 'css');
    $this->addFormattedFieldMapping('field_catalyst_custom_js', 'js_custom', 'js');
    // File field mapping
    $this->addFileFieldMapping('field_catalyst_custom_files', 'files_custom', '|');
  }
}
