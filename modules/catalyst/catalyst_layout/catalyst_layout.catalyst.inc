<?php

/**
 * @file
 * Catalyst hook implementations for Catalyst Layout
 */

/**
 * Implements hook_catalyst_plugin_info().
 */
function catalyst_layout_catalyst_plugin_info() {
  return array(
    'layout' => array(
      'title' => t('Layouts'),
      'entity_type' => 'catalyst',
      'bundle' => 'layout',
      'exportables' => TRUE,
      'migration' => array(
        'class_name' => 'CatalystLayoutMigration',
      ),
      'migration sources' => array('block', 'doctype', 'stylesheet', 'javascript', 'file'),
      'crud' => array(
        'admin' => array('path' => 'admin/structure/layout'),
        'add' => array('path' => 'admin/structure/layout/add'),
        'edit' => array(
          'path' => 'admin/structure/layout/%eckentity',
          'entity_id' => 3,
        ),
        'delete' => array(
          'path' => 'admin/structure/layout/%eckentity/delete',
          'entity_id' => 3,
        ),
        'view' => array(
          'path' => 'admin/structure/layout/%eckentity/view',
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
function catalyst_layout_catalyst_export_candidates($group) {
  if ($group['type'] == 'layout') {
    return catalyst_export_entity_candidates($group['type']);
  }
}

/**
 * Implements hook_catalyst_export_dependencies().
 */
function catalyst_layout_catalyst_export_dependencies($export, $group) {
  if (isset($group['entity_type'])) {
    $dependencies = array();

    // Determine dependencies for entities that rely on layouts
    if (!empty($export->field__layout)) {
      $wrapper = entity_metadata_wrapper($group['entity_type'], $export);
      $layout = $wrapper->field__layout;
      catalyst_add_export($dependencies, 'layout', $layout->getIdentifier());
    }
    return $dependencies;
  }
}

/**
 * Implements hook_catalyst_prepare_export().
 */
function catalyst_layout_catalyst_prepare_export($export, $group, $exports) {
  $wrapper = entity_metadata_wrapper($group['entity_type'], $export);
  $block_placements = array();
  $block_placement_block_ids = array();
  foreach ($wrapper->field__blockplacements__layout->value() AS $placement) {
    if (catalyst_export_exists($placement['block_id'], 'block', $exports)) {
      $block_placement_block_ids[] = $placement['block_id'];
      unset($placement['block_id']);
      $block_placements[] = $placement;
    }
  }
  return (object) array(
    'id' => $wrapper->getIdentifier(),
    'title' => $wrapper->title->value(),
    'machine' => $wrapper->field__machine->machine->value(),
    'created' => $wrapper->created->value(),
    'changed' => $wrapper->changed->value(),
    'regions' => $wrapper->field__layout_regions->value(),
    'block_placements' => $block_placements,
    'block_placement_block_ids' => $block_placement_block_ids,
    'doctype' => catalyst_export_helper_filter_references(
      $wrapper->field__doctype, 'doctype', $exports),
    'content' => entity_valval($wrapper->field__body),
    'drupal_processing' => $wrapper->field__drupal_processing->value(),
    'drupal_css_options' => $wrapper->field__layout_drupal_css->value(),
    'drupal_js_options', $wrapper->field__layout_drupal_js->value(),
    'page_title_pattern' => $wrapper->field__layout_page_title_pattern->value(),
    'show_messages' => $wrapper->field__layout_show_messages->value(),
    'debug' => $wrapper->field__debug->value(),
    'files_custom' => catalyst_export_helper_files(
      $wrapper->field__files, $wrapper->getIdentifier()),
    'blocks_reference' => catalyst_export_helper_filter_references(
      $wrapper->field__blocks_related, 'block', $exports),
    'css_includes' => catalyst_export_helper_filter_references(
      $wrapper->field__media_stylesheets__layout, 'stylesheet', $exports),
    'js_includes' => catalyst_export_helper_filter_references(
      $wrapper->field__media_javascripts__layout, 'javascript', $exports),
    'files_shared' => catalyst_export_helper_filter_references(
      $wrapper->field__media_files, 'file', $exports),
    'css_custom' => entity_valval($wrapper->field__css__layout),
    'js_custom' => entity_valval($wrapper->field__js__layout),
    'html_head' => entity_valval($wrapper->field__html_head),
    'preprocess_php' => entity_valval($wrapper->field__preprocess),
    'onselect' => entity_valval($wrapper->field__onselect),
    'ondeselect' => entity_valval($wrapper->field__ondeselect),
  );
}

/**
 * Implements hook_catalyst_ignore_menus_alter().
 */
function catalyst_layout_catalyst_ignore_menus_alter(&$ignore_menus) {
  $ignore_menus['devel'] = TRUE;
}
