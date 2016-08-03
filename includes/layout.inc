<?php

/**
 * @file
 * Base layout handling functions.
 */

/**
 * Initialize the catalyst layout.
 */
function catalyst_layout_initialize() {
  $current_layout =& drupal_static('catalyst_layout');
  if (!isset($current_layout)) {
    $resolved_layout = FALSE;
    // Initialize the default layout if one is set
    if ($default_layout = variable_get('catalyst_layout_default', FALSE)) {
      $resolved_layout = machine_load_single('field__machine', $default_layout, 'catalyst', 'layout');
    }
    // This might not be the right way to implement this as the layout
    // shouldn't be altered but this gives other modules a chance to call
    // catalyst_set_layout().
    drupal_alter('catalyst_layout', $resolved_layout);

    catalyst_set_layout($resolved_layout);
  }
}

function catalyst_get_layout() {
  catalyst_layout_initialize();
  return catalyst_set_layout();
}

function catalyst_set_layout($layout = NULL, $entity_type = 'catalyst') {
  $stored_layout =& drupal_static('catalyst_layout');
  if ($layout !== NULL) {
    // Prevent "changing" the layout to the same layout
    if (isset($stored_layout)) {
      switch (true) {
        // $layout is null, false, or an ID and matches the stored layout
        case (!$layout || is_int($layout)) && $stored_layout->getLayoutID() == $layout:
            return $stored_layout;
        // $layout is an entity and matches the stored layout.
        case is_a($layout, 'Entity'):
          $wrapper = entity_metadata_wrapper($entity_type, $layout);
          if (isset($wrapper->field__machine) && $stored_layout->getLayoutID() == entity_valval($wrapper->field__machine)) {
            return $stored_layout;
          }
      }
    }

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
