<?php
/**
 * @file
 * csv_taxonomy_term.inc
 */

abstract class BetterMigrationCSVTaxonomyTerm extends BetterMigrationCSV {
  protected $vocabularyMachineName;
  protected function getVocabularyMachineName() {
    return $this->vocabularyMachineName;
  }

  // @todo
  protected function initMap() {
    return new MigrateSQLMap($this->machineName,
      array(
        'name' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationTerm::getKeySchema()
    );
  }

  protected function initDestination() {
    return new MigrateDestinationTerm($this->getVocabularyMachineName());
  }
}
