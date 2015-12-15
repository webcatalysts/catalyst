<?php

/**
 * @file
 * SQL mapping for Better migrate.
 */

trait BetterMigrationMapSQL {
  abstract protected function mappingKeys();
  protected function initMap() {
    return new MigrateSQLMap($this->machineName, $this->getMappingKeys(), $this->getDestinationKeySchema());
  }

  protected function getMappingKeys() {
    if (!empty($this->arguments['mapping_keys'])) {
      return $this->arguments['mapping_keys'];
    }
    return $this->mappingKeys();
  }
}

trait BetterMigrationMapSQLSimple {
  protected function initMap() {
    return new MigrateSQLMap($this->machineName, $this->getMapping(), $this->getDestinationKeySchema());
  }

  protected function getMappingIDKey() {
    if (!empty($this->arguments['map_id_key'])) {
      return $this->arguments['map_id_key'];
    }
    elseif (!empty($this->mapIDKey)) {
      return $this->mapIDKey;
    }
    // trigger error
  }

  protected function getMapping() {
    return array(
      $this->getMappingIDKey() => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
    );
  }
}

trait BetterMigrationMapSQLString {
  use BetterMigrationMapSQlSimple;
  protected function getMapping() {
    return array(
      $this->getMappingIDKey() => array(
        'type' => 'varchar',
        'length' => $this->getMappingIDLength(),
        'not null' => TRUE,
      ),
    );
  }

  protected function getMappingIDLength() {
    if (!empty($this->arguments['map_id_length'])) {
      return $this->arguments['map_id_length'];
    }
    elseif (empty($this->mapIDLength)) {
      $this->mapIDLength = 255;
    }
    return $this->mapIDLength;
  }
}
