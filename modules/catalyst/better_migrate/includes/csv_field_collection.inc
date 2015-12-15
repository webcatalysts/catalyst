<?php
/**
 * @file
 * csv_field_collection.inc
 */


abstract class BetterMigrationCSVFieldCollection extends BetterMigrationCSV {
  protected $fcFieldName;
  protected $hostEntityType = 'node';

  protected function initDestination() {
    if (empty($this->fcFieldName)) {
      throw new Exception(t('Empty $fcFieldName encountered in @class_name', array('@class_name' => get_class($this))));
    }
    return new MigrateDestinationFieldCollection($this->fcFieldName, $this->destinationOptions());
  }

  protected function initMap() {
    return new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationFieldCollection::getKeySchema()
    );
  }

  protected function destinationOptions() {
    return array('host_entity_type' => $this->hostEntityType) +
      MigrateDestinationNode::options(LANGUAGE_NONE, 'full_html');
  }
}
