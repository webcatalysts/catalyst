<?php

/**
 * @file
 * Entity destination handler for Better Migrate.
 */

trait BetterMigrationDestinationNode {
  protected function initDestination() {
    return new MigrateDestinationNode(
      $this->getNodeType(),
      $this->getNodeOptions()
    );
  }

  protected function getNodeType() {
    if (!empty($this->arguments['destination_options']['node_type'])) {
      return $this->arguments['destination_options']['node_type'];
    }
    if (!empty($this->nodeType)) {
      return $this->nodeType;
    }
    // trigger error
  }

  protected function getNodeOptions() {
    return MigrateDestinationNode::options(LANGUAGE_NONE, 'full_html');
  }

  protected function getDestinationKeySchema() {
    return MigrateDestinationNode::getKeySchema();
  }
}
