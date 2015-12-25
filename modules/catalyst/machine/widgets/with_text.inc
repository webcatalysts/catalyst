<?php

/**
 * @file
 * Machine widget functions for the with text widget.
 */

function machine_with_text_widget(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  return $element + array(
    '#error_title' => $instance['label'],
    'text' => array(
      '#type' => 'textfield',
      '#default_value' => isset($items[$delta]) ? $items[$delta]['text'] : NULL,
    ),
    'machine' => array(
      '#type' => 'machine_name',
      '#default_value' => isset($items[$delta]) ? $items[$delta]['machine'] : NULL,
      //'#disabled' => isset($items[$delta]),
      '#machine_name' => array(
        'exists' => 'machine_exists_dummy',
        'source' => array($instance['field_name'], $langcode, $delta, 'text'),
      ),
      '#required' => FALSE,
    ),
  );
}
