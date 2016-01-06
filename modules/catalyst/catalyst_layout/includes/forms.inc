<?php

/**
 * @file
 *
 * Admin related forms for Catalyst layouts.
 */

/**
 * Form for settings the global site default layout.
 */
function catalyst_default_layout_form($form, &$form_state) {
  if ($layout_options = catalyst_default_layout_options()) {
    catalyst_form_load_include($form_state, 'forms', 'layout');
    $form['#prefix'] = '<div id="catalyst-default-layout-form-wrapper" class="container-inline">';
    $form['#suffix'] = '</div>';
    $ajax = array(
      'callback' => 'catalyst_default_layout_form_ajax',
      'wrapper' => 'catalyst-default-layout-form-wrapper',
    );
    $form['catalyst_layout_default'] = array(
      '#type' => 'select',
      '#title' => t('Default Layout'),
      '#options' => array('' => t('No default')) + $layout_options,
      '#default_value' => variable_get('catalyst_layout_default', FALSE),
      //'#ajax' => $ajax + array('trigger_as' => array('actions', 'submit')),
    );
    $form['actions'] = array('#type' => 'actions');
    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Set default layout'),
      //'#ajax' => $ajax,
      '#submit' => array('catalyst_default_layout_form_submit'),
    );
    return $form;
  }
  // No layout options.
  variable_set('catalyst_default_layout', FALSE);
  return array();
}

/**
 * Submit callback for settings the site default layout.
 */
function catalyst_default_layout_form_submit($form, &$form_state) {
  variable_set('catalyst_layout_default', $form_state['values']['catalyst_layout_default']);
  if ($layout_id = variable_get('catalyst_layout_default', FALSE)) {
    $layout = catalyst_load_single($layout_id);
    $layout_text = $layout->title;
  }
  else $layout_text = t('No default');
  drupal_set_message(t('The default layout has been changed to %layout_text', array(
    '%layout_text' => filter_xss_admin($layout_text),
  )));
}

/**
 * AJAX callback for the default layout form.
 */
function catalyst_default_layout_form_ajax($form, $form_state) {
  return $form;
}

/**
 * Default layout settings form for node types.
 *
 * Only returns a form when there are non-catalyst node types.
 */
function catalyst_node_default_layout_form($form, &$form_state) {
  // Need to implement a hook here
  $custom_node_types = array_diff_key(node_type_get_names(), array('cpage' => 1));
  $layout_options = catalyst_default_layout_options();
  if (!$custom_node_types || !$layout_options) {
    return array();
  }
  foreach ($custom_node_types AS $type => $type_name) {
    // We'll need to detect whether the node type has a catalyst layout field.
    $default = variable_get('catalyst_layout_default_node_' . $type, FALSE);
    $form[$type] = array(
      '#title' => filter_xss_admin($type_name),
      '#type' => 'select',
      '#options' => array('' => t('Use the site default')) + $layout_options,
      '#default_value' => $default,
      '#field_suffix' => l(t('configure'), 'admin/structure/layout/settings/' . $type),
    );
  }
  return $form;
}

/**
 * Get default layout options. Requires the layout's doctype to have the
 * "text/html" content type.
 *
 * If/when layouts can set their own headers and not have layouts, this will
 * need to be updated.
 */
function catalyst_default_layout_options() {
  $options = array();
  if ($layouts = catalyst_load('layout')) {
    foreach ($layouts AS $layout) {
      $wrapper = entity_metadata_wrapper('catalyst', $layout);
      if ($doctype = $wrapper->field__doctype) {
        if ($doctype->field__doctype_content_type->value() == 'text/html') {
          $options[$wrapper->getIdentifier()] = $wrapper->label();
        }
      }
    }
  }
  return $options;
}
