<?php

/**
 * @file
 */

/**
 * Implements hook_migrate_api().
 */
function catalyst_doctype_migrate_api() {
  return array(
    'api' => 2,
    'migrations' => array(
      'DoctypesInstall' => array(
        'class_name' => 'CatalystDoctypesMigration',
        'group_name' => 'catalyst_install',
        'data_directory' => 'profiles/catalyst/install-data',
        'xml_filename' => 'doctypes-install.xml',
        'item_xpath' => '/doctypes/doctype',
        'item_xpath_id' => 'machine_name',
        'map_id_key' => 'machine_name',
        'description' => t('Generic doctypes imported on installation'),
      ),
    ),
  );
}

class CatalystDoctypesMigration extends BetterMigration {
  use BetterMigrationSourceXML;
  use BetterMigrationDestinationEntity;
  use BetterMigrationMapSQLString;

  protected $entityType = 'catalyst';
  protected $entityBundle = 'doctype';

  protected function sourceFields() {
    return array(
      'machine_name' => t('The unique identifier for the doctype'),
      'handle' => t('Doctype Title'),
      'header' => t('Doctype Header'),
      'footer' => t('Doctype Footer'),
      'onselect' => t('Doctype OnSelect'),
      'ondeselect' => t('Doctype OnDeselect'),
    );
  }

  public function prepareRow($row) {
  }

  protected function mapFields() {
    $this->addFieldMapping('field_doctype_handle:machine', 'machine_name');
    $this->addFieldMapping('title', 'handle');
    $this->addFieldMapping('field_doctype_header', 'header')
      ->callbacks('html_entity_decode');
    $this->addFieldMapping('field_doctype_footer', 'footer')
      ->callbacks('html_entity_decode');
    $this->addFieldMapping('field_doctype_onselect', 'onselect');
    $this->addFieldMapping('field_doctype_ondeselect', 'ondeselect');
    $this->addFieldMapping('type')->defaultValue($this->entityBundle);
    $this->addFieldMapping('language')->defaultValue(LANGUAGE_NONE);
    $this->addUnmigratedDestinations(array(
      'id',
      'path',
      'field_doctype_handle',
      'created',
      'changed',
    ));
  }
}
