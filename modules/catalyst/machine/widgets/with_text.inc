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
        '_field_name' => $instance['field_name'],
      ),
      '#required' => FALSE,
    ),
    '#element_validate' => array('machine_with_text_widget_validate'),
    '#unique_per' => $field['settings']['unique_values_per'],
    '#unique_text' => $field['settings']['unique_text'],
    '#unique_text' => TRUE,
  );
}

function machine_with_text_widget_validate($element, &$form_state, &$form) {
  // Don't check empty items
  if (empty($element['machine']['#value'])) {
    return;
  }
  switch ($element['#unique_per']) {
    case 'entity':
      machine_with_text_widget_validate_per_entity($element, $form_state, $form);
      break;
  }
}

/**
 * Validate a with text widget (per entity).
 */
function machine_with_text_widget_validate_per_entity($element, &$form_state, &$form) {
  if ($element['#delta'] > 0) { // No reason to validate first item
    $values = $form_state['values'][$element['#field_name']][$element['#language']];

    if (empty($values['text'])) {
      return;
    }

    $error_field_base = implode('][', $element['#parents']);
    $error_variables = array(
      '%field_title' => $element['#error_title'],
    );
    // Validate upwards starting with the current delta
    for ($i = $element['#delta']-1; $i >= 0; $i--) {
      if (!isset ($values[$i])) {
        continue;
      }
      if ($element['#unique_text']
        && $element['machine']['#value'] == $values[$i]['machine']
        && $element['text']['#value'] == $values[$i]['text']) {
        $error_message = t('%field_title requires unique machine names and text.', $error_variables);
        form_set_error($error_field_base, $error_message);
      }
      elseif ($element['machine']['#value'] == $values[$i]['machine']) {
        $error_message = t('%field_title requires unique machine names.', $error_variables);
        form_set_error($error_field_base . '][machine', $error_message);
      }
      elseif ($element['#unique_text'] && $element['text']['#value'] == $values[$i]['text']) {
        $error_message = t('%field_title requires unique text.', $error_variables);
        form_set_error($error_field_base . '][text', $error_message);
      }
    }
  }
}
