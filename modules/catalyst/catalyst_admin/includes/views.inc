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
  elseif (in_array($action, array('view', 'edit')) && strtolower($text) != $action) {
    return $text;
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


/**
 * Provides action links for catalyst admin views.
 *
 * @param $links array
 *   Contains one or more links expecting the following:
 *   - title: The translated link text
 *   - path: The path the link should link to
 *   - destination: (optional) the destination to append to the link query
 *     string
 *   - access: (optional) can be a string for a single permission or an
 *     array containing multiple permissions.
 *
 * @return
 *   When the user has access to one or more links (or no permissions are
 *   defined), a unorder list of links classed "action-links" is returned.
 */
function catalyst_admin_action_links(array $links) {
  $return = array();
  foreach ($links AS $class => $link) {
    if (isset($link['access'])) {
      foreach ((array)$link['access'] AS $permission) {
        if (!user_access($permission)) {
          continue(2);
        }
      }
    }
    $return[$class] = array(
      'title' => $link['title'],
      'href' => $link['path'],
    );
    if (!empty($link['destination'])) {
      $return[$class]['query']['destination'] = $link['destination'];
    }
  }
  if ($return) {
    return theme('links', array(
      'links' => $return,
      'attributes' => array('class' => 'action-links'),
    ));
  }
}
