<?php

/**
 * @file
 * Functions used by the default machine widget.
 */
function machine_default_widget(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  return $element += array(
    'machine' => array(
      '#type' => 'machine_name',
      '#title' => $instance['label'],
      '#machine_name' => array(
        'exists' => '_machine_exists',
      ),
      '#default_value' => isset($items[$delta]) ? $items[$delta]['machine'] : NULL,
    ),
  );
}

function _machine_exists() { return FALSE; }
