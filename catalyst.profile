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
 * Implements hook_form_FORM_ID_alter() for install_configure_form().
 *
 * Alter the "configure" installation step
 */
function catalyst_form_install_configure_form_alter(&$form, $form_state) {
  form_load_include($form_state, 'install', 'catalyst');
  _catalyst_form_install_configure_form_alter($form, $form_state);
}

/**
 * Implements hook_element_info().
 */
function catalyst_element_info() {
  return array(
    'layout' => array(
      '#theme' => 'layout',
      '#theme_wrappers' => array('doctype'),
      '#layout' => NULL,
      '#doctype' => NULL,
    ),
    'doctype' => array(
      '#theme' => 'doctype',
    ),
  );
}

/**
 * Implements hook_theme().
 */
function catalyst_theme() {
  return array(
    'doctype' => array(
      'render element' => 'page',
    ),
    'layout' => array(
      'render element' => 'page',
    ),
  );
}

/**
 * Implements hook_page_delivery_callback_alter().
 *
 * @see drupal_deliver_page()
 */
function catalyst_page_delivery_callback_alter(&$delivery_callback) {
  if ($delivery_callback != 'drupal_deliver_html_page') {
    return;
  }
  global $theme;
  // Might need to allow subthemes here for hybrid integrations
  //if ($theme == 'notheme' && !path_is_admin($_GET['q'])) {
  if ($theme == 'notheme') {
    $delivery_callback = 'catalyst_deliver_html_page';
  }
}

function catalyst_load($bundle, $ids = FALSE, $conditions = array(), $reset = FALSE) {
  $conditions['type'] = $bundle;
  return entity_load('catalyst', $ids, $conditions, $reset);
}

function catalyst_load_single($id) {
  return entity_load_single('catalyst', $id);
}
