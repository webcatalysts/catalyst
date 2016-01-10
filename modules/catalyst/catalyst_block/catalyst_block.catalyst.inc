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
        'admin' => array('path' => 'admin/content/block'),
        'add' => array('path' => 'admin/content/block/add'),
        'edit' => array(
          'path' => 'admin/content/block/%eckentity',
          'entity_id' => 3,
        ),
        'delete' => array(
          'path' => 'admin/content/block/%eckentity/delete',
          'entity_id' => 3,
        ),
        'view' => array(
          'path' => 'admin/content/block/%eckentity/view',
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
 * Implements hook_catalyst_prepare_export().
 */
function catalyst_block_catalyst_prepare_export($export, $group, $exports) {
  $wrapper = entity_metadata_wrapper($group['entity_type'], $export);

  $block_placements = array();
  $block_placement_layout_ids = array();
  foreach ($wrapper->field__blockplacements__block->value() AS $placement) {
    if (catalyst_export_exists($placement['layout_id'], 'layout', $exports)) {
      $block_placement_layout_ids[] = $placement['layout_id'];
      unset($placement['layout_id']);
      $block_placements[] = $placement;
    }
  }
  return (object) array(
    'id' => $wrapper->getIdentifier(),
    'title' => $wrapper->label(),
    'created' => $wrapper->created->value(),
    'changed' => $wrapper->changed->value(),
    'machine_name' => $wrapper->field__machine->machine->value(),
    'content' => entity_valval($wrapper->field__body),
    'css_custom' => entity_valval($wrapper->field__css),
    'js_custom' => entity_valval($wrapper->field__js),
    'preprocess_php' => entity_valval($wrapper->field__preprocess),
    'block_placements' => $block_placements,
    'block_placement_layout_ids' => $block_placement_layout_ids,
    'files_custom' => catalyst_export_helper_files(
      $wrapper->field__files, $wrapper->getIdentifier()),
    // Filter reference items
    'js_includes' => catalyst_export_helper_filter_references(
      $wrapper->field__media_javascripts, 'javascript', $exports),
    'css_includes' => catalyst_export_helper_filter_references(
      $wrapper->field__media_stylesheets, 'stylesheet', $exports),
    'files_shared' => catalyst_export_helper_filter_references(
      $wrapper->field__media_files, 'file', $exports),
  );
}
