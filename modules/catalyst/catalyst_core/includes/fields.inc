<?php

/**
 * @file
 * Catalyst field related functions and callbacks.
 */

/**
 * Returns a list of all fields defined by Catalyst.
 */
function catalyst_list_fields() {
  // Need to do more than static caching
  $fields = &drupal_static(__FUNCTION__);
  if (!isset($fields)) {
    $fields = array();
    $cache = _field_info_field_cache();
    foreach (array_keys(field_info_bundles('catalyst')) AS $bundle) {
      $fields = array_merge($fields, $cache->getBundleInstances('catalyst', $bundle));
    }
    $fields = array_merge($fields, $cache->getBundleInstances('node', 'cpage'));
  }
  return $fields;
}

/**
 * Page callback override for the Field UI field list.
 *
 * Removes (non-safe) catalyst fields from the list to minimize clutter.
 *
 * Note: The alternate Catalyst Field's List is provided by catalyst_admin.
 *
 * @see catalyst_core_menu_alter().
 */
function catalyst_field_ui_clean_field_list() {
  $instances = field_info_instances();
  unset($instances['catalyst']);
  $instances['node'] = array_diff_key($instances['node'], catalyst_node_types());
  return catalyst_field_ui_field_list($instances);
}

/**
 *
 * Note: The Catalyst field's list menu item is provided by catalyst_admin.
 */
function catalyst_field_ui_catalyst_field_list() {
  $instances = array_intersect_key(field_info_instances(), array_flip(array('catalyst', 'node')));
  $instances['node'] = array_intersect_key($instances['node'], array_flip(array('cpage')));
  return catalyst_field_ui_field_list($instances);
}

/**
 * Print a field list according to the $instances parameter.
 *
 * @see field_ui_field_list()
 */
function catalyst_field_ui_field_list($instances) {
  $bundles = field_info_bundles();
  $field_types = field_info_field_types();
  $modules = system_rebuild_module_data();
  $header = array(t('Field name'), t('Field type'), t('Used in'));
  $rows = array();
  foreach ($instances as $entity_type => $type_bundles) {
    foreach ($type_bundles as $bundle => $bundle_instances) {
      foreach ($bundle_instances as $field_name => $instance) {
        $field = field_info_field($field_name);

        // Initialize the row if we encounter the field for the first time.
        if (!isset($rows[$field_name])) {
          $rows[$field_name]['class'] = $field['locked'] ? array('menu-disabled') : array('');
          $rows[$field_name]['data'][0] = $field['locked'] ? t('@field_name (Locked)', array('@field_name' => $field_name)) : $field_name;
          $module_name = $field_types[$field['type']]['module'];
          $rows[$field_name]['data'][1] = $field_types[$field['type']]['label'] . ' ' . t('(module: !module)', array('!module' => $modules[$module_name]->info['name']));
        }

        // Add the current instance.
        $admin_path = _field_ui_bundle_admin_path($entity_type, $bundle);
        $rows[$field_name]['data'][2][] = $admin_path ? l($bundles[$entity_type][$bundle]['label'], $admin_path . '/fields') : $bundles[$entity_type][$bundle]['label'];
      }
    }
  }
  foreach ($rows as $field_name => $cell) {
    $rows[$field_name]['data'][2] = implode(', ', $cell['data'][2]);
  }
  if (empty($rows)) {
    $output = t('No fields have been defined yet.');
  }
  else {
    // Sort rows by field name.
    ksort($rows);
    $output = theme('table', array('header' => $header, 'rows' => $rows));
  }
  return $output;
}
