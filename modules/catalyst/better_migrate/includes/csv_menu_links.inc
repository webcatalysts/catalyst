<?php
/**
 * @file
 * csv_menu_links.inc
 */


abstract class BetterMigrationCSVMenuLinks extends BetterMigrationCSV {

  protected function initDestination() {
    return new MigrateDestinationMenuLinks();
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
      MigrateDestinationMenuLinks::getKeySchema()
    );
  }
}
