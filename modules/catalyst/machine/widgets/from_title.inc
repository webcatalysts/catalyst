<?php

/**
 * @file
 * Widget functions for the from title widget.
 */
function machine_from_title_widget(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  $source = array('title');

  // Support for inline_entity_form
  if (isset($form_state['inline_entity_form']) && in_array('form', $element['#field_parents'])) {
    $source = $element['#field_parents'];
    array_reverse($source);
    array_push($source, 'title');
  }

  return $element += array(
    'machine' => array(
      '#type' => 'machine_name',
      '#title' => $instance['label'],
      '#machine_name' => array(
        'exists' => 'machine_dummy_exists',
        'source' => $source,
      ),
      '#default_value' => isset($items[$delta]) ? $items[$delta]['machine'] : NULL,
    ),
  );
}
