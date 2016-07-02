<?php

/**
 * @file
 * Catalyst hook implementations for Catalyst Block.
 */

/**
 * Implements hook_catalyst_plugin_info().
 */
function catalyst_block_catalyst_plugin_info() {
  return array(
    'block' => array(
      'title' => t('Blocks'),
      'entity_type' => 'catalyst',
      'bundle' => 'block',
      'exportables' => TRUE,
      'migration' => array(
        'class_name' => 'CatalystBlockMigration',
      ),
      'migration sources' => array('layout', 'stylesheet', 'javascript', 'file'),
      'crud' => array(
        'admin' => array(
          'path' => 'admin/catalyst/block',
          'menu_item' => array(
            'title' => 'Blocks',
            'weight' => -10,
          ),
        ),
        'add' => array('path' => 'admin/catalyst/block/add'),
        'edit' => array(
          'path' => 'admin/catalyst/block/%eckentity',
          'entity_id' => 3,
        ),
        'delete' => array(
          'path' => 'admin/catalyst/block/%eckentity/delete',
          'entity_id' => 3,
        ),
        'view' => array(
          'path' => 'admin/catalyst/block/%eckentity/view',
          'entity_id' => 3,
          'menu_item' => FALSE,
        ),
      ),
    ),
  );
}

/**
 * Implements hook_catalyst_export_candidates().
 */
function catalyst_block_catalyst_export_candidates($group) {
  $args = func_get_args();
  if ($group['type'] == 'block') {
    return catalyst_export_entity_candidates($group['type']);
  }
}

/**
 * Implements hook_catalyst_export_dependencies().
 */
function catalyst_block_catalyst_export_dependencies($export, $group) {
  if (isset($group['entity_type'])) {
    $dependencies = array();
    $wrapper = entity_metadata_wrapper($group['entity_type'], $export);
    // These fields need to be consolidated into one
    $block_refs_fields = array('field__blocks_related', 'field__blocks_related');
    foreach ($block_refs_fields AS $field) {
      if (isset($wrapper->{$field})) {
        foreach ($wrapper->{$field} AS $item) {
          catalyst_add_export($dependencies, 'block', $item->getIdentifier());
        }
      }
    }
    // Determine dependencies for entities using block placements
    $placement_fields = array('field__blockplacements__layfield', 'field__blockplacements__layout');
    foreach ($placement_fields AS $field) {
      if (isset($wrapper->{$field})) {
        foreach ($wrapper->{$field} AS $item) {
          $block_id = $item->block_id->value();
          if (!isset($dependencies['block'][$block_id])) {
            catalyst_add_export($dependencies, 'block', $block_id);
          }
        }
      }
    }
    return $dependencies;
  }
}

/**
 * Implements hook_catalyst_export_alter().
 */
function catalyst_block_catalyst_export_alter(&$export, $original, $group, $exports) {
  if (!isset($group['entity_type'])) {
    return;
  }
  if (!isset($export->blocks_reference) && isset($wrapper->field__blocks_related)) {
    $export->blocks_reference = catalyst_export_helper_filter_references($wrapper->field__blocks_related, 'block', $exports);
  }
  $wrapper = entity_metadata_wrapper($group['entity_type'], $original);
  if (!isset($export->block_placements)) {
    $placement_fields = array(
      'field__blockplacements__block' => 'layout_id',
      'field__blockplacements__layout' => 'block_id',
      'field__blockplacements__layfield' => 'block_id',
    );
    foreach ($placement_fields AS $field_name => $id_key) {
      if (isset($wrapper->{$field_name})) {
        $export->block_placements = array();
        $export->block_placement_ids = array();
        foreach ($wrapper->{$field_name}->value() AS $placement) {
          $export->block_placement_ids[] = $placement[$id_key];
          unset($placement[$id_key]);
          $export->block_placements[] = $placement;
        }
        break(1);
      }
    }
  }
}

/**
 * Implements hook_catalyst_prepare_export().
 */
function catalyst_block_catalyst_prepare_export($export, $group, $exports) {
  return (object) array();
}
