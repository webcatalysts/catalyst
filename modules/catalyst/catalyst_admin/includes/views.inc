<?php

/**
 * @file
 * Views related functions, callbacks and helper functions for Catalyst Admin.
 */

/**
 * Create a link to a specific action for a catalyst eck entity.
 *
 * Included here rather than eck.inc because it is primarily (only) used in
 * views.
 */
function catalyst_admin_eck_entity_link($bundle, $id, $text, $action = 'edit', $prefix = 'admin/structure', $options = array()) {
  if (eck__entity_menu_access($action, 'catalyst', $bundle, $id)) {
    return l($text, $prefix . '/' . $bundle . '/' . $id . '/' .$action, $options);
  }
}

/**
 *
 * @param $view
 *   The view object.
 * @param $plural_text
 *   The plural version of the bundle. Eg. doctypes, layouts, etc.
 * @param $create_options array
 *   An of array of options for an optional create link when no items
 *   have been created yet including:
 *     - path: Path to the create form for the bundle
 *     - bundle: The singlular text of the bundle. Eg. doctype, layout, etc.
 *     - access: (optional) Create access permission for the bundle
 *     - text: (optional) Override the default text for th create link.
 *     - destination: (optional)a destination path for the create link.
 *     - options: (optional) an array of additional options to pass to the link
 */
function catalyst_admin_views_no_results($view, $bundle_plural, $options = array()) {
  // Check for exposed input
  if (empty($view->exposed_input)) {
    // No exposed input, no items exist
    $output = t('No @bundle_plural have been created yet.', array(
      '@bundle_plural' => $bundle_plural,
    ));
    if (isset($options['path']) && $options['bundle']) {
      $options += array(
        'text' => t('Create a @bundle &raquo', array('@bundle' => $options['bundle'])),
        'access' => 'eck add ' . $options['bundle'] . ' layout entities',
        'options' => array('html' => TRUE),
      );
      if (user_access($options['access'])) {
        if (!empty($options['destination'])) {
          $options['options']['query'] = array('destination' => $options['destination']);
        }
        $output .= ' '. l($options['text'], $options['path'], $options['options']);
      }
    }
  }
  else {
    $output =  t('No @bundle_plural were found that match your current search filters.', array(
      '@bundle_plural' => $bundle_plural,
    ));
  }
  return $output;
}
