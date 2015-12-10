<?php
/**
 * @file
 * catalyst_block.features.inc
 */

/**
 * Implements hook_eck_bundle_info().
 */
function catalyst_block_eck_bundle_info() {
  $items = array(
    'catalyst_block' => array(
      'machine_name' => 'catalyst_block',
      'entity_type' => 'catalyst',
      'name' => 'block',
      'label' => 'Block',
      'config' => array(),
    ),
  );
  return $items;
}
