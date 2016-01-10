<?php

/**
 * @file
 * Functions and callbacks related to ECK customizations for Catalyst.
 */

/**
 * Blocks all menu access to the catalyst entity type eck administration pages.
 *
 * Note: Access is restored according to eck permissions when
 * catalyst_devel when is installed.
 */
function catalyst_eck__entity_type_menu_alter(&$items) {
  if (isset($items['admin/structure/entity-type'])) {
    $items['admin/structure/entity-type'] = array_merge(
      $items['admin/structure/entity-type'], array(
      'page callback' => 'catalyst_eck__entity_type_list',
      'file path' => catalyst_get_path() . '/includes',
      'file' => 'eck.inc',
    ));
  }

  foreach (_catalyst_eck__entity_type_paths() AS $path) {
    if (isset($items[$path])) {
      catalyst_menu_item_disable($items[$path]);
    }
  }
}

/**
 * Blocks all menu access to the catalyst entity type eck administration pages.
 *
 * Note: Access is restored according to eck permissions when
 * catalyst_devel when is installed.
 */
function catalyst_eck__bundle_menu_alter(&$items) {
  $entity_info = entity_get_info('catalyst');
  foreach (array_keys($entity_info['bundles']) AS $bundle) {
    foreach (_catalyst_eck__bundle_paths($bundle) AS $path) {
      if (isset($items[$path])) {
        catalyst_menu_item_disable($items[$path]);
      }
    }
  }
}

/**
 * Blocks all menu access to catalyst entities.
 *
 * Note: Access is restored by catalyst_admin when it's installed.
 *
 * @see catalyst_core_menu_alter().
 */
function catalyst_eck__entity_menu_alter(&$items) {
  $entity_info = entity_get_info('catalyst');
  foreach (array_keys($entity_info['bundles']) AS $bundle) {
    $crud_info = get_bundle_crud_info('catalyst', $bundle);
    foreach ($crud_info AS $action_info) {
      $action_path = $action_info['path'];
      catalyst_menu_item_disable($menu_item[$action_path]);
    }
    $admin_info = get_bundle_admin_info('catalyst', $bundle);
    $admin_path = $admin_info['path'];
    catalyst_menu_item_disable($items[$admin_path]);
  }
}

/**
 * List of entity type paths that are altered by catalyst.
 */
function _catalyst_eck__entity_type_paths($entity_type = 'catalyst') {
  $path = eck__entity_type__path();
  return array(
    $path . '/' . $entity_type,
    $path . '/' . $entity_type . '/delete',
    $path . '/' . $entity_type . '/properties',
    $path . '/' . $entity_type . '/edit',
    $path . '/' . $entity_type . '/add',
  );
}

/**
 * List of bundle paths that are altered by catalyst.
 */
function _catalyst_eck__bundle_paths($bundle, $entity_type = 'catalyst') {
  $entity_info = entity_get_info($entity_type);
  $path = $entity_info['bundles'][$bundle]['admin']['path'];
  return array(
    $path,
    $path . '/delete',
    $path . '/edit',
    $path . '/add',
    $path . '/fields',
    $path . '/display',
  );
}

/**
 * Replacement page handler for ECK's admin/structure/entity-type menu item.
 *
 * Removes the catalyst entity type from the list of entity types.
 */
function catalyst_eck__entity_type_list() {
  $path = eck__entity_type__path();
  $header = array(t('Name'), array('data' => t('Operations'), 'colspan' => '1'));
  $rows = array();

  $entity_types = EntityType::loadAll();
  // The only change by catalyst
  unset($entity_types['catalyst']);
  usort($entity_types, 'eck_alphabetical_cmp');

  foreach ($entity_types as $entity_type) {
    $allowed_operations = '';
    // Check that the user has permissions to delete:
    if (eck__multiple_access_check(array('eck administer entity types', 'eck delete entity types'))) {
      $allowed_operations = l(t("delete"), "{$path}/{$entity_type->name}/delete");
    }

    if (eck__multiple_access_check(array(
      'eck administer bundles',
      'eck list bundles',
      "eck administer {$entity_type->name} bundles",
      "eck list {$entity_type->name} bundles",
    ))) {
      $label = l(t("@el", array("@el" => $entity_type->label)), "{$path}/{$entity_type->name}");
    }
    else {
      $label = t("@el", array("@el" => $entity_type->label));
    }

    $rows[] = array($label, $allowed_operations);
  }

  $build['entity_table'] = array(
    '#theme' => 'table',
    '#header' => $header,
    '#rows' => $rows,
  );

  return $build;
}
