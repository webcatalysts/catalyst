<?php

/**
 * @file
 * Catalyst hook implementations for Catalyst Page.
 */

/**
 * Implements hook_catalyst_plugin_info().
 */
function catalyst_page_catalyst_plugin_info() {
  return array(
    'page' => array(
      'title' =>  t('Pages'),
      'entity_type' => 'catalyst',
      'bundle' => 'page',
      'exportables' => TRUE,
      'migration' => array(
        'class_name' => 'CatalystEntityPageMigration',
      ),
      'migration sources' => array(
        'package', 'block', 'layout', 'stylesheet', 'javascript', 'file'
      ),
      'crud' => array(
        'admin' => array('path' => 'admin/catalyst/page'),
        'add' => array('path' => 'admin/catalyst/page/add'),
        'edit' => array(
          'path' => 'admin/catalyst/page/%eckentity',
          'entity_id' => 3,
        ),
        'delete' => array(
          'path' => 'admin/catalyst/page/%eckentity/delete',
          'entity_id' => 3,
        ),
        'view' => NULL,
      ),
    ),
  );
}

/**
 * Implements hook_catalyst_export_candidates().
 */
function catalyst_page_catalyst_export_candidates($group) {
  if ($group['type'] == 'page') {
    return catalyst_export_entity_candidates($group['type']);
  }
}

/**
 * Implements hook_catalyst_prepare_export().
 */
function catalyst_page_catalyst_prepare_export($export, $group, $exports) {
  return (object) array();
}
