<?php

/**
 * @file
 * Machine field validation callback and helper functions.
 */

/**
 * Callback for validating machine fields.
 */
function _machine_field_validate_unique($entity_type, $entity, $field, $instance, $langcode, $items, &$errors) {

  $unique_per  = $field['settings']['unique_per'];
  $with_text  = $field['type'] == 'machine_with_text';
  $unique_text = $with_text && $field['settings']['unique_text'];
  $field_name  = $field['field_name'];

  $machine_values = $text_values = array();
  foreach ($items AS $delta => $item) {
    $machine_values[$delta] = $item['machine'];
    if ($unique_text) {
      $text_values[$delta] = $item['text'];
    }
  }

  // Validate per entity with multiple values
  if (count($items) > 1) {
    // Traverse values in reverse checking for duplicate values in the entity
    for ($delta = count($items)-1; $delta >= 0; $delta--) {
      // Check for incomplete data first
      if ($with_text && empty($items[$delta]['machine']) && !empty($items[$delta]['text'])) {
        // Expecting machine and text, got only text
        $errors[$field_name][$langcode][$delta][] = machine_error_empty($instance);
        continue;
      }
      elseif ($with_text && empty($items[$delta]['text']) && !empty($items[$delta]['machine'])) {
        // Expecting text and machine, got only machine
        $errors[$field_name][$langcode][$delta][] = machine_error_text_empty($instance);
        continue;
      }
      elseif (empty($items[$delta]['machine']) || empty($unique_per)) {
        // Continue if not expecting text and machine is empty or unique values
        // are not required by the field settings
        continue;
      }

      // Begin checking for duplicate values within the entity
      $machine_search = array_search($items[$delta]['machine'], $machine_values);
      $machine_match = $machine_search !== FALSE && $machine_search !== $delta;
      if ($unique_text) {
        $text_search = array_search($items[$delta]['text'], $text_values);
        $text_match = ($text_search !== FALSE && $text_search !== $delta);
      }
      // Check matches and provide a "descriptive" error
      if ($unique_text && $machine_match && $text_match) {
        // Both text and machine are not unique
        $errors[$field_name][$langcode][$delta][] = machine_error_not_unique_both($instance, $items[$delta]);
      }
      elseif ($machine_match) {
        // Machine is not unique
        $errors[$field_name][$langcode][$delta][] = machine_error_not_unique($instance, $items[$delta]['machine']);
      }
      elseif ($unique_text && $text_match) {
        // Text is not unique
        $errors[$field_name][$langcode][$delta][] = machine_error_not_unique_text($instance, $items[$delta]['text']);
      }
    }
  }

  // Nothing more to do if unique per entity or unique values not required by
  // the field settings
  if ($unique_per == 'entity' || empty($unique_per)) {
    return;
  }

  // No support for non sql fields afaik
  if ($field['storage']['type'] != 'field_sql_storage') {
    // @todo Add watchdog message?
    return;
  }

  list($entity_id,,$bundle) = entity_extract_ids($entity_type, $entity);
  $storage = $field['storage']['details']['sql']['FIELD_LOAD_CURRENT'];
  $table = array_keys($storage)[0];
  $machine_column = $storage[$table]['machine'];
  $text_column = $with_text ? $storage[$table]['text'] : '';

  // Initialize the query based on the field's table
  $query = db_select($table, 't');
  $query->addField('t', $machine_column, 'machine');

  if ($unique_text) {
    // Checking machine and text values for duplicates
    $query->addField('t', $text_column, 'text');
    $query->condition(db_or()
      ->condition($machine_column, $machine_values, 'IN')
      ->condition($text_column, $text_values, 'IN')
    );
  }
  else {
    // Checking machine only for duplicates
    $query->condition($machine_column, $machine_values, 'IN');
  }

  // Get the entity id of matches when unique_per is field or entity_type
  if ($entity_id && in_array($unique_per, array('field', 'entity_type'))) {
    $query->addField('t', 'entity_id');
  }

  // Get the entity_type and bundle
  if ($unique_per == 'field') {
    $query->addField('t', 'entity_type');
    $query->addField('t', 'bundle');
  }
  elseif ($unique_per == 'entity_type') {
    $query->condition('entity_type', $entity_type, '=');
    $query->addField('t', 'bundle');
  }
  elseif ($unique_per == 'bundle') {
    $query->condition('entity_type', $entity_type, '=');
    $query->condition('bundle', $bundle, '=');
    if ($entity_id) {
      // When unique per bundle we can exclude the current entity unless it's
      // just being created
      $query->condition('entity_id', $entity_id, '!=');
    }
  }

  $result = $query->execute();
  foreach ($result AS $match) {
    // Compare retrieved values to ensure the match isn't the current entity
    if (_machine_match_is_current_entity($unique_per, $match, $entity_id, $entity_type, $bundle)) {
      // Matched the current entity, continue without error
      continue;
    }

    // Loop each item to determine what matches
    foreach ($items AS $delta => $item) {
      // Skip empty items (silly that core field hasn't already pruned them)
      if (machine_field_is_empty($item, $field)) {
        continue;
      }

      $machine_match = $match->machine == $item['machine'];
      // Check for unique text based on field type and settings
      $text_match = $unique_text && $match->text == $item['text'];

      // Provide descriptive error based on matches
      if ($machine_match && $text_match) {
        $errors[$field_name][$langcode][$delta][] = machine_error_not_unique_both($instance, $item);
      }
      elseif ($machine_match) {
        $errors[$field_name][$langcode][$delta][] = machine_error_not_unique($instance, $item['machine']);
      }
      elseif ($text_match) {
        $errors[$field_name][$langcode][$delta][] = machine_error_not_unique_text($instance, $item['text']);
      }
    }
  }
}

function _machine_match_is_current_entity($unique_per, $match, $entity_id, $entity_type, $bundle) {
  switch ($unique_per) {
    case 'field':
      return $entity_id && $match->entity_id == $entity_id && $match->entity_type == $entity_type && $match->bundle == $bundle;
    case 'entity_type':
      return $entity_id && $match->entity_id == $entity_id && $match->bundle == $bundle;
  }
  return FALSE;
}

/**
 * Validation error when both the machine and text are not unique.
 *
 * Only applicable when $field['settings']['unique_text'] is TRUE
 */
function machine_error_not_unique_both($instance, $item) {
  return array(
    'error' => __FUNCTION__,
    'message' => t('%name: requires %machine_label and %text_label to be unique.',
      array(
        '%name' => $instance['label'],
        '%machine_label' => $instance['widget']['settings']['machine_field_label'],
        '%text_label' => $instance['widget']['settings']['text_field_label'],
        '%machine_value' => $item['machine'],
        '%text_value' => $item['text'],
      )
    ),
  );
}

/**
 * Validation error when the machine value is not unique.
 */
function machine_error_not_unique($instance, $machine) {
  return array(
    'error' => __FUNCTION__,
    'error_field' => 'machine',
    'message' => t('%field_label: Duplicate %machine_label encountered (%machine_value).',
      array(
        '%field_label' => $instance['label'],
        '%machine_label' => $instance['widget']['settings']['machine_field_label'],
        '%machine_value' => $machine,
      )
    ),
  );
}

/**
 * Validation error when the machine text is not unique.
 */
function machine_error_not_unique_text($instance, $text) {
  return array(
    'error' => __FUNCTION__,
    'error_field' => 'text',
    'message' => t('%field_label: Duplicate %text_label encountered (%text_value).',
      array(
        '%field_label' => $instance['label'],
        '%text_label' => $instance['widget']['settings']['text_field_label'],
        '%text_value' => $text,
      )
    ),
  );
}

/**
 * Validation error when text is given but machine is empty.
 */
function machine_error_empty($instance) {
  return array(
    'error' => __FUNCTION__,
    'error_field' => 'machine',
    'message' => t('%field_label: %machine_label cannot be blank.',
      array(
        '%field_label' => $instance['label'],
        '%machine_label' => $instance['widget']['settings']['machine_field_label'],
      )
    ),
  );
}

/**
 * Validation error when machine is given but text is empty.
 */
function machine_error_text_empty($instance) {
  return array(
    'error' => __FUNCTION__,
    'error_field' => 'text',
    'message' => t('%field_label: %text_label cannot be blank.',
      array(
        '%field_label' => $instance['label'],
        '%text_label' => $instance['widget']['settings']['text_field_label'],
      )
    ),
  );
}
