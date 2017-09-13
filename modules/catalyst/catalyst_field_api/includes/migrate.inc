<?php

/**
 * @file
 */

abstract class MigrateBlockPlacementFieldHandler extends MigrateFieldHandler {
  abstract public function fields();

  public function prepare($entity, array $field_info, array $instance, array $values) {
    $arguments = array();
    if (isset($values['arguments'])) {
      $arguments = array_filter($values['arguments']);
      unset($values['arguments']);
    }
    $language = $this->getFieldLanguage($entity, $field_info, $arguments);
    $delta = 0;
    foreach ($values AS $value) {
      $return[$language][$delta] = (array)$value;
      if (isset($arguments)) {
        foreach ($arguments AS $arg => $val) {
          if (is_array($arguments[$arg])) {
            $return[$language][$delta][$arg] = $val[$delta];
          }
          else {
            $return[$language][$delta][$arg] = $val;
          }
        }
      }
      $delta++;
    }
    return isset($return) ? $return : NULL;
  }
}

class MigrateBlockPlacementBlockFieldHandler extends MigrateBlockPlacementFieldHandler {
  public function __construct() {
    $this->registerTypes(array(
      'block_placement_block',
      'block_placement_entity',
    ));
  }
  public function fields() {
    return array(
      'block_id' => t('Subfield: Block ID'),
      'layout_id' => t('Subfield: Layout ID'),
    );
  }
}

class MigrateBlockPlacementLayoutFieldHandler extends MigrateBlockPlacementFieldHandler {
  public function __construct() {
    $this->registerTypes(array(
      'block_placement_layout',
      'block_placement_layout_field',
    ));
  }
  public function fields() {
    return array(
      'block_id' => t('Subfield: Block ID'),
    );
  }
}
