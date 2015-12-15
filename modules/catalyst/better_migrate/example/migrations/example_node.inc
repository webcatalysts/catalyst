<?php

/**
 * @file
 * example_node.inc
 */

class EveryFieldMigration extends BetterMigrationCSVNode {
  //const GROUP = MIGRATION_GROUP_PRODUCTION;
  protected $csvFilename = 'example_node.csv';
  protected $nodeType = 'every_field';
  protected $description = 'Import example for every_field';

  protected function columns() {
    return array(
      array('id', t('ID'), t('A unique, positive integer that the system uses to reference each row.')),
      array('title', t('Title'), t('The title for the node. 255 characters max.')),
      array('summary', t('Summary'), t('The summary for this node. (optional) This will be automatically pulled from the body if left unfilled.')),
      array('body', t('Body'), t('The body content for the node. Can contain full_html')),
      array('file', t('File'), t('An example, general use file, like a PDF.')),
      array('image', t('Image'), t('An example image.')),
      array('list_boolean', t('List Boolean'), t('1 or 0')),
      array('list_integer', t('List Integer'), t('Possible values: 1,2,3')),
      array('list_float', t('List Float'), t('Possible values: 1,2,3')),
      array('list_text', t('List Text'), t('Possible values: S,M,L')),
      array('float', t('Float'), t('Example float field.')),
      array('integer', t('Integer'), t('Example integer field. Should be a positive number.')),
      array('decimal', t('Decimal'), t('Example decimal field.')),
      array('terms', t('Tags'), t('A comma separate list of tags')),
      array('text', t('Text'), t('An example text field.')),
      array('text_long', t('Long Text'), t('An example long text field')),
      array('path', t('Path'), t('The custom path to this page.')),
      array('status', t('Status')),
      array('promoted', t('Promoted')),
      array('sticky', t('Sticky')),
    );
  }

  protected function mapFields() {
    $this->addFieldMapping('uid')
      ->defaultValue(1);

    $this->addFieldMapping('title', 'title');

    $this->addFieldMapping('body:summary', 'summary')
      ->callbacks('utf8_encode');
    $this->addFieldMapping('body', 'body')
      ->callbacks('utf8_encode');

    // Map an image field, pull files from directory
    $this->addFieldMapping('every_field_image', 'image');
    $this->addFieldMapping('every_field_image:source_dir')
      ->defaultValue($this->dataDirectory() . '/files');

    // Map a regular file field, pull files from directly
    $this->addFieldMapping('every_field_file', 'file');
    $this->addFieldMapping('every_field_file:source_dir')
      ->defaultValue($this->dataDirectory() . '/files');

    $this->addFieldMapping('every_field_list_boolean', 'list_boolean');
    $this->addFieldMapping('every_field_list_integer', 'list_integer');
    $this->addFieldMapping('every_field_list_float', 'list_float');
    $this->addFieldMapping('every_field_list_text', 'list_text');

    $this->addFieldMapping('every_field_float', 'float');
    $this->addFieldMapping('every_field_integer', 'integer');
    $this->addFieldMapping('every_field_decimal', 'decimal');

    // Handle terms, create if term doens't exist
    $this->addFieldMapping('every_field_term_reference', 'terms')
      ->separator('|');
    $this->addFieldMapping('every_field_term_reference:create_term')
      ->defaultValue(1);

    $this->addFieldMapping('every_field_text', 'text');
    $this->addFieldMapping('every_field_text_long', 'text_long');

    // Handle paths
    $this->addFieldMapping('path', 'path');
    $this->addFieldMapping('pathauto')->defaultValue(0);

    // Handle core node flags
    $this->addFieldMapping('status', 'status')
      ->defaultValue(1);
    $this->addFieldMapping('promote', 'promoted')
      ->defaultValue(0);
    $this->addFieldMapping('sticky', 'sticky')
      ->defaultValue(0);
  }

  protected function dataDirectory() {
    return drupal_get_path('module', 'better_migrate_example') . '/migrations/' . $this::DATA_DIRECTORY;
  }
}

class TestEveryFieldMigration extends EveryFieldMigration {
  //const GROUP = MIGRATION_GROUP_TESTING;

  protected function mapFields() {
    parent::mapFields();
    $this->removeFieldMapping('every_field_file');
    $this->removeFieldMapping('every_field_file:source_dir');
    $this->removeFieldMapping('every_field_image');
    $this->removeFieldMapping('every_field_image:source_dir');
  }
}
