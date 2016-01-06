<?php

/**
 * @file
 * Admin page callbacks and functions for Catalyst Layout.
 */

/**
 * Page callback for layout settings page.
 *
 * Includes multiple forms.
 */
function catalyst_layout_admin_settings_page() {
  $page = array();
  catalyst_include('forms', 'layout');
  $page['default_layout'] = drupal_get_form('catalyst_default_layout_form');
  $page['node_layout'] = drupal_get_form('catalyst_node_default_layout_form');
  return $page;
}

