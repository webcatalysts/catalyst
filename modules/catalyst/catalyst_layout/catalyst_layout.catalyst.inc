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
      'migration sources' => array(
        'package', 'block', 'doctype', 'stylesheet','javascript', 'file',
      ),
      'crud' => array(
        'admin' => array(
          'path' => 'admin/catalyst/layout',
          'menu_item' => array(
            'title' => 'Layouts',
            'weight' => 10,
          ),
        ),
        'add' => array(
          'path' => 'admin/catalyst/layout/add',
        ),
        'edit' => array(
          'path' => 'admin/catalyst/layout/%eckentity',
          'entity_id' => 3,
        ),
        'delete' => array(
          'path' => 'admin/catalyst/layout/%eckentity/delete',
          'entity_id' => 3,
        ),
        'view' => array(
          'path' => 'admin/catalyst/layout/%eckentity/view',
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
      catalyst_add_export($dependencies, 'layout', catalyst_export_entity_id($layout));
    }
    return $dependencies;
  }
}

/**
 * Implements hook_catalyst_prepare_export().
 */
function catalyst_layout_catalyst_prepare_export($export, $group, $exports) {
  $wrapper = entity_metadata_wrapper($group['entity_type'], $export);
  return (object) array(
    'regions' => $wrapper->field__layout_regions->value(),
    'drupal_css_options' => $wrapper->field__layout_drupal_css->value(),
    'drupal_js_options' => $wrapper->field__layout_drupal_js->value(),
    'page_title_pattern' => $wrapper->field__layout_page_title_pattern->value(),
    'show_messages' => $wrapper->field__layout_show_messages->value(),
  );
}

/**
 * Implements hook_catalyst_export_alter().
 */
function catalyst_layout_catalyst_export_alter(&$export, $original, $group, $exports) {
  if (isset($group['entity_type'])) {
    $wrapper = entity_metadata_wrapper($group['entity_type'], $original);
    if (!isset($export->layout) && isset($wrapper->field__layout)) {
      $export->layout = catalyst_export_helper_filter_references($wrapper->field__layout, 'layout', $exports);
    }
  }
}

/**
 * Implements hook_catalyst_ignore_menus_alter().
 */
function catalyst_layout_catalyst_ignore_menus_alter(&$ignore_menus) {
  $ignore_menus['devel'] = TRUE;
}
