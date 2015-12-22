<?php

/**
 * @file
 * Common functions used in multiple machine widgets.
 */

/**
 * Primary callback for validating whether a machine value is unique.
 *
 * @param
 *   - $value The machine value to check
 *   - $element The form element being validated
 *   - $form_state of the form being validated
 *
 * @return
 *   TRUE If the value is a duplicate (not unique).
 *   FALSE If the value is a duplicate (not unique).
 */
function machine_value_exists($value, $element, $form_state) {
  $field = field_info_field($element['#machine_name']['_field_name']);
  switch ($field['settings']['unique_values_per']) {
    case 'entity':
      break;
    case 'entity_type':
      break;
    case 'bundle':
      break;
    case 'field':
      break;
  }
  return FALSE;
}

function machine_exists_dummy() {
  return FALSE;
}
