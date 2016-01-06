<?php

/**
 * @file
 * Uncommon functions and callbacks.
 */

/**
 * Alters the field ui overview form to prune catalyst fields from the existing
 * field options.
 *
 * @see catalyst_admin_form_field_ui_field_overview_form_alter().
 */
function catalyst_field_ui_field_overview_form_after_build($form, &$form_state) {
  // We're on a non-catalyst entity form, remove catalyst fields from existing
  // field options leaving safe fields
  catalyst_include('fields');
  $catalyst_fields = array_keys(catalyst_list_fields());
  $safe_fields = array_keys(module_invoke_all('catalyst_safe_fields'));
  $options = &$form['fields']['_add_existing_field']['field_name']['#options'];
  $catalyst_options = array();
  foreach ($options AS $value => $text) {
    if (in_array($value, $safe_fields)) {
      $catalyst_options[$value] = $text;
    }
    elseif (in_array($value, $catalyst_fields)) {
      unset($options[$value]);
    }
  }

  // If there are catalyst options, separate them with optgroups
  if (count($catalyst_options)) {
    $options = array(
      '' => array_shift($options),
      t('Existing fields') => $options,
      t('Catalyst fields') => $catalyst_options,
    );
  }
  // If there are no other existing fields remove add existing field element
  elseif (count($options) <= 1) {
    // Setting the access to false had no affect, hopefully this doesn't
    // cause any other problems.
    unset($form['fields']['_add_existing_field']);
  }
  return $form;
}
