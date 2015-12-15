<?php
/**
 * @file
 * csv_user.inc
 */


abstract class BetterMigrationCSVUser extends BetterMigrationCSV {
  protected function initDestination() {
    return new MigrateDestinationUser();
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
      MigrateDestinationUser::getKeySchema()
    );
  }
}
