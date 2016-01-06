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
    if (isset($export->field_cpage_layout)) {
      $wrapper = entity_metadata_wrapper($group['entity_type'], $export);
      $layout = $wrapper->field_cpage_layout;
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
  foreach ($wrapper->field_layout_blocks->value() AS $placement) {
    if (catalyst_export_exists($placement['block_id'], 'block', $exports)) {
      $block_placement_block_ids[] = $placement['block_id'];
      unset($placement['block_id']);
      $block_placements[] = $placement;
    }
  }
  return (object) array(
    'id' => $wrapper->getIdentifier(),
    'title' => $wrapper->title->value(),
    'created' => $wrapper->created->value(),
    'changed' => $wrapper->changed->value(),
    'regions' => $wrapper->field_layout_regions->value(),
    'block_placements' => $block_placements,
    'block_placement_block_ids' => $block_placement_block_ids,
    'doctype' => catalyst_export_helper_filter_references(
      $wrapper->field_layout_doctype, 'doctype', $exports),
    'content' => entity_valval($wrapper->field_layout_content),
    'drupal_processing' => $wrapper->field_catalyst_drupal_processing->value(),
    'drupal_css_options' => $wrapper->field_layout_drupal_css->value(),
    'drupal_js_options', $wrapper->field_layout_drupal_js->value(),
    'page_title_pattern' => $wrapper->field_layout_page_title_pattern->value(),
    'show_messages' => $wrapper->field_layout_show_messages->value(),
    'debug' => $wrapper->field_layout_debug->value(),
    'files_custom' => catalyst_export_helper_files(
      $wrapper->field_catalyst_custom_files, $wrapper->getIdentifier()),
    'blocks_reference' => catalyst_export_helper_filter_references(
      $wrapper->field_catalyst_blocks_add, 'block', $exports),
    'css_includes' => catalyst_export_helper_filter_references(
      $wrapper->field_layout_includes_css, 'stylesheet', $exports),
    'js_includes' => catalyst_export_helper_filter_references(
      $wrapper->field_layout_includes_js, 'javascript', $exports),
    'files_shared' => catalyst_export_helper_filter_references(
      $wrapper->field_catalyst_shared_files, 'file', $exports),
    'css_custom' => entity_valval($wrapper->field_layout_css),
    'js_custom' => entity_valval($wrapper->field_layout_js),
    'html_head' => entity_valval($wrapper->field_layout_html_head),
    'preprocess_php' => entity_valval($wrapper->field_layout_preprocess),
    'onselect' => entity_valval($wrapper->field_layout_onselect),
    'ondeselect' => entity_valval($wrapper->field_layout_ondeselect),
  );
}

/**
 * Implements hook_catalyst_ignore_menus_alter().
 */
function catalyst_layout_catalyst_ignore_menus_alter(&$ignore_menus) {
  $ignore_menus['devel'] = TRUE;
}
