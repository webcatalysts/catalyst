<?php

/**
 * @file
 * Base layout handling functions.
 */

/**
 * Initialize the catalyst layout.
 */
function catalyst_layout_initialize() {
  $layout =& drupal_static('catalyst_layout');
  if (!isset($layout)) {
    $layout_entity = FALSE;
    // Initialize the default layout if one is set
    if ($layout_entity_id = variable_get('catalyst_layout_default', FALSE)) {
      $layout_entity = entity_load_single('catalyst', $layout_entity_id);
    }
    // Initialize the layout with or without a layout entity
    $layout = new CatalystEntityLayout($layout_entity);
  }
}

function catalyst_get_layout() {
  catalyst_layout_initialize();
  return catalyst_set_layout();
}

function catalyst_set_layout($layout = NULL) {
  $stored_layout =& drupal_static('catalyst_layout');
  if ($layout !== NULL) {
    if (is_int($layout)) {
      $layout = entity_load_single('catalyst', $layout, array('type' => 'layout'));
    }
    $stored_layout = new CatalystEntityLayout($layout);
  }
  return $stored_layout;
}

/**
 * Get the current doctype (from the layout)
 */
function catalyst_get_doctype() {
  $layout = catalyst_get_layout();
  return $layout->getDoctype();
}
