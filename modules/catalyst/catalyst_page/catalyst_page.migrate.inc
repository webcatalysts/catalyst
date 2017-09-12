<?php

/**
 * @file
 */

class CatalystPageMigration extends CatalystEntityMigration {
  protected $entityBundle = 'page';

  protected function sourceFields() {
    return array(
      'access_php' => t('Access PHP'),
      'menu_options' => t('Menu options'),
      'layout' => t('Layout'),
      'content' => t('Content'),
      'css_custom' => t('Custom CSS'),
      'stylesheets' => t('Stylesheet Includes'),
      'js_custom' => t('Custom JS'),
      'javascripts' => t('Javascript Includes'),
      'files_custom' => t('Custom Files'),
      'files_shared' => t('Shared Files'),
      'block_placements' => t('Block placements'),
      'block_placement_ids' => t('Block placement block IDs'),
      'blocks_reference' => t('Block references'),
      'html_head' => t('Custom HTML Head'),
      'preprocess_php' => t('Preprocess PHP'),
    ) + parent::sourceFields();
  }

  protected function mapFields() {
    parent::mapFields();
    // Menu options see prepare()
    $this->addFieldMapping('field__menu', NULL);
    $this->addFieldMapping('field__menu:serialization', NULL);
    // Block Placements
    $this->addFieldMapping('field__blockplacements__layfield', 'block_placements');
    $this->addReferenceFieldMapping('field__blockplacements__layfield:block_id', 'block_placement_ids', 'block');
    // Entity Placements
    $this->addFieldMapping('field___block_placements_entity', 'entity_placements');
    $this->addReferenceFieldMapping('field___block_placements_entity:block_id', 'entity_placements_block_id', 'block');
    $this->addReferenceFieldMapping('field___block_placements_entity:layout_id', 'entity_placements_layout_id', 'block');
    // File field mapping
    $this->addFileFieldMapping('field__files', 'files_custom');
    // Reference field mappings
    $this->addReferenceFieldMapping('field__layout', 'layout', 'layout');
    $this->addReferenceFieldMapping('field__media_stylesheets__page', 'stylesheets', 'stylesheet');
    $this->addReferenceFieldMapping('field__media_javascripts__page', 'javascripts', 'javascript');
    $this->addReferenceFieldMapping('field__media_files', 'files_shared', 'file');
    $this->addReferenceFieldMapping('field__blocks_related', 'blocks_reference', 'block');
    // Formmatted field mappings
    $this->addFormattedFieldMapping('field__access', 'access_php', 'catalyst_php');
    $this->addFormattedFieldMapping('field__body', 'content', 'catalyst_html');
    $this->addFormattedFieldMapping('field__css__page', 'css_custom', 'catalyst_css');
    $this->addFormattedFieldMapping('field__js__page', 'js_custom', 'catalyst_js');
    $this->addFormattedFieldMapping('field__html_head', 'html_head', 'catalyst_html');
    $this->addFormattedFieldMapping('field__preprocess', 'preprocess_php', 'catalyst_php');
  }

  public function prepare($entity, $row) {
    parent::prepare($entity, $row);
    $language = isset($entity->language) ? $entity->language : LANGUAGE_NONE;
    $entity->field__menu[$language][0]['value'] = drupal_json_decode(drupal_json_encode($row->menu_options));
  }

  public function postImport() {
    parent::postImport();
    menu_rebuild();
  }
}
