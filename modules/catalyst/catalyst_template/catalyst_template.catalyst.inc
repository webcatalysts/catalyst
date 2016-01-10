<?php

/**
 * @file
 * Catalyst hooks for Catalyst template.
 */

function catalyst_template_catalyst_plugin_info() {
  return array(
    'template' => array(
      'entity_type' => 'catalyst',
      'bundle' => 'template',
      'crud' => array(
        'admin' => array(
          'path' => 'admin/structure/template',
          'menu_item' => array(
            'title' => 'Templates',
            'page callback' => 'catalyst_template_admin_list',
            'file path' => catalyst_get_path('template') . '/includes',
            'file' => 'admin.inc',
          ),
          'parent_menu_item' => array(
            'path' => 'admin/structure/template/list',
            'title' => 'List',
            'weight' => -10,
          ),
        ),
        'add' => array(
          'path' => 'admin/structure/template/add/%/%',
          'menu_item' => array(
            'page callback' => 'catalyst_template_admin_add',
            'page arguments' => array(4,5),
            'file path' => catalyst_get_path('template') . '/includes',
            'file' => 'admin.inc',
          ),
        ),
        'edit' => array(
          'path' => 'admin/structure/template/%eckentity',
          'entity_id' => 3,
        ),
        'delete' => array(
          'path' => 'admin/structure/template/%eckentity/delete',
          'entity_id' => 3,
        ),
        'view' => array(
          'path' => 'admin/structure/template/%eckentity/view',
          'entity_id' => 3,
          'menu_item' => FALSE,
        ),
      ),
    ),
  );
}

