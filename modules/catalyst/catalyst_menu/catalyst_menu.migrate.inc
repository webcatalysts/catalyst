<?php

/**
 * @file
 */

/**
 * Catalyst Menu migration.
 *
 * Easiest migration ever!
 */
class CatalystMenuMigration extends CatalystBaseMigration {
  use BetterMigrateSourceJSON;
  use BetterMigrateMapSQLSimpleString;
  use BetterMigrateDestinationMenu;
  protected $sourceIDField = 'menu_name';
  protected function sourceFields() {
    return $this->getDestination()->fields();
  }
  protected function mapFields() {
    $this->addSimpleMappings(array_keys($this->sourceFields()));
  }
}

/**
 * Catalyst Menu Link Migration.
 */
class CatalystMenuLinkMigration extends CatalystBaseMigration {
  use BetterMigrateSourceJSON;
  use BetterMigrateMapSQLSimpleInteger;
  use BetterMigrateDestinationMenuLinksTable;

  protected $sourceIDField = 'mlid';
  protected function mapFields() {
    // Simple mappings
    $this->addSimpleMappings(array(
      'menu_name', 'router_path', 'link_path', 'depth', 'has_children',
      'external', 'expanded', 'link_title', 'options', 'module', 'hidden',
      'weight', 'customized',
    ));

    $this->addReferenceFieldMapping('plid', 'plid', $this->machineName);

    for($i = 1; $i <= 9; $i++) {
      $this->addReferenceFieldMapping('p'.$i, 'p'.$i, $this->machineName);
    }

    // Map the potential cpage_id to the updated field
    // We might need to extend the CatalystMigration base class to allow
    // hooks to alter migrations
    $this->addReferenceFieldMapping('updated', 'cpage_id', 'cpage');
  }
  protected function sourceFields() {
    return $this->getDestination()->fields() + array(
      'cpage_id' => t('Page ID'),
    );
  }

  public function prepareRow(&$row) {
    // Recursively case options as an array
    $row->options = (array)json_decode(json_encode($row->options), true);

    // Ensure the title attribute is set
    if (!isset($row->options['attributes']['title'])) {
      $row->options['attributes']['title'] = $row->link_title;
    }
  }

  public function prepare(&$entity, $row) {
    // Detect cpage_id and update link path
    if (!empty($entity->updated)) {
      $entity->link_path = 'node/' . $entity->updated;
    }
    $entity->updated = 0;
  }
}
