<?php

/**
 * @file
 * Catalyst hooks for Catalyst core.
 */

function catalyst_core_catalyst_plugin_info() {
  return array(
    'package' => array(
      'entity_type' => 'catalyst',
      'bundle' => 'package',
      'crud' => array(
        'admin' => array('path' => 'admin/structure/package'),
        'add' => array('path' => 'admin/structure/package/add'),
        'edit' => array(
          'path' => 'admin/structure/package/%eckentity',
          'entity_id' => 3,
        ),
        'delete' => array(
          'path' => 'admin/structure/package/%eckentity/delete',
          'entity_id' => 3,
        ),
        'view' => array(
          'path' => 'admin/structure/package/%eckentity/view',
          'entity_id' => 3,
          'menu_item' => FALSE,
        ),
      ),
    ),
  );
}

