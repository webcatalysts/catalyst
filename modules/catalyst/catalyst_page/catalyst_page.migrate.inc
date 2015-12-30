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
      'blocks_ref' => t('Block references'),
      'html_head' => t('Custom HTML Head'),
      'preprocess_php' => t('Preprocess PHP'),
    ) + parent::sourceFields();
  }

  protected function mapFields() {
    parent::mapFields();
    // File field mapping
    $this->addFileFieldMapping('field_catalyst_custom_files', 'files_custom', '|');
    // Reference field mappings
    $this->addReferenceFieldMapping('field_cpage_layout', 'layout', 'layout', FALSE);
    $this->addReferenceFieldMapping('field_cpage_includes_css', 'css_includes', 'stylesheet', ',');
    $this->addReferenceFieldMapping('field_cpage_includes_js', 'js_includes', 'javascript', ',');
    $this->addReferenceFieldMapping('field_catalyst_shared_files', 'files_shared', 'file', ',');
    $this->addReferenceFieldMapping('field_cpage_blocks_add', 'blocks_ref', 'block', ',');
    // Formmatted field mappings
    $this->addFormattedFieldMapping('field_cpage_content', 'content', 'cpage_html');
    $this->addFormattedFieldMapping('field_cpage_custom_css', 'css_custom', 'css');
    $this->addFormattedFieldMapping('field_cpage_custom_js', 'js_custom', 'js');
    $this->addFormattedFieldMapping('field_cpage_head', 'html_head', 'cpage_html');
    $this->addFormattedFieldMapping('field_cpage_preprocess', 'preprocess_php', 'php');
    // Unmapped destinations
    $this->addUnmigratedDestinations(array(
      'promote', 'sticky',
    ));
  }
}
