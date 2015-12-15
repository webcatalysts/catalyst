<?php

/**
 * @file
 * Entity destination handler for Better Migrate.
 */

trait BetterMigrationDestinationEntity {
  protected function initDestination() {
    return new MigrateDestinationEntityAPI(
      $this->getEntityType(),
      $this->getEntityBundle(),
      $this->getDestinationOptions()
    );
  }

  protected function getEntityType() {
    if (!empty($this->arguments['destination_options']['entity_type'])) {
      return $this->arguments['destination_options']['entity_type'];
    }
    if (!empty($this->entityType)) {
      return $this->entityType;
    }
    // trigger error
  }

  protected function getEntityBundle() {
    if (!empty($this->arguments['destination_options']['entity_bundle'])) {
      return $this->arguments['destination_options']['entity_bundle'];
    }
    if (!empty($this->entityBundle)) {
      return $this->entityBundle;
    }
    // trigger error
  }

  protected function getDestinationKeySchema() {
    return MigrateDestinationEntityAPI::getKeySchema(
      $this->getEntityType(),
      $this->getEntityBundle()
    );
  }
}
