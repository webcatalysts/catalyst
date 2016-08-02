<?php

/**
 * @file
 * Uncommon functions and callbacks for Catalyst Admin.
 */

/**
 * Form after build callback for vbo forms.
 *
 * @see catalyst_admin_form_alter().
 */
function catalyst_admin_views_form_after_build($form, &$form_state) {
  // Move view output to appear above vbo actions
  $form['output']['#weight'] = -100;
  $view = $form_state['build_info']['args'][0];
  // Hide vbo when view has no results
  if (isset($form['select']) && empty($view->result)) {
    $form['select']['#access'] = FALSE;
  }
  return $form;
}

/**
 * Form after build callback for views exposed forms.
 *
 * @see catalyst_admin_form_alter().
 */
function catalyst_admin_views_exposed_form_after_build($form, &$form_state) {
  $form['#attached']['js'][] = catalyst_get_path('admin') . '/js/views.js';

  $form['#attributes']['class'][] = 'container-inline';
  if (isset($form['secondary'])) {
    $form['secondary']['#attributes']['class'][] = 'container-inline';
  }
  return $form;
}
