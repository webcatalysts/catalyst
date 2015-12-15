<?php
/**
 * @file
 * Enables modules and site configuration for a catalyst site installation.
 */
ini_set('display_errors', 1);
error_reporting(E_ALL);
require_once 'profiles/catalyst/includes/common.inc';
require_once 'profiles/catalyst/includes/layout.inc';
require_once 'profiles/catalyst/includes/theme.inc';


/**
 * Implements hook_element_info().
 */
function catalyst_element_info() {
  return array(
    'layout' => array(
      '#show_messages' => TRUE,
      '#theme' => 'layout',
    ),
  );
}

/**
 * Implements hook_theme().
 */
function catalyst_theme() {
  return array(
    'layout' => array(
      'render element' => 'layout',
    ),
  );
}

/**
 * Implements hook_page_delivery_callback_alter().
 * 
 * @see drupal_deliver_page()
 */
function catalyst_page_delivery_callback_alter(&$delivery_callback) {
  global $theme, $catalyst_layout;
  drupal_theme_initialize();
  // Might need to allow subthemes here for hybrid integrations
  if (isset($catalyst_layout) && $theme == 'notheme') {
    $delivery_callback = 'catalyst_deliver_page';
  }
}

/**
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Allows the profile to alter the site configuration form.
 */
function catalyst_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = $_SERVER['SERVER_NAME'];
}
