<?php

/**
 * @file
 * Add "Save & Edit" buttons to catalyst entity and node forms.
 *
 * Currently this applies to all eck entity and node forms but it should
 * detect catalyst verses custom entities and allow being disabled for
 * non-catalyst forms.
 *
 * This is closely modeled after the save_edit module which only supports
 * nodes.
 *
 * @see catalyst_admin_form_eck__entity__form_alter().
 * @see catalyst_admin_form_node_form_alter().
 */

/**
 * Add a Save & Edit button to a form's actions.
 */
function catalyst_admin_save_edit_form_alter(&$form, &$form_state) {
  // Depend on the base form id and actions element
  if (!isset($form_state['build_info']['base_form_id']) || !isset($form['actions'])) {
    return;
  }
  $save_edit_forms = array(
    // base form id => forms submit callback function
    'eck__entity__form' => array(
      'submit callback' => 'eck__entity__form_submit',
      'redirect callback' => 'eck__entity_form__redirect',
    ),
    'node_form' => array(
      'submit callback' => 'node_form_submit',
      'redirect callback' => 'node_form_save_edit_redirect',
    ),
  );
  $base_form_id = $form_state['build_info']['base_form_id'];
  if (array_key_exists($base_form_id, $save_edit_forms)) {
    $form['actions']['catatalyst_save_edit'] = array(
      '#type' => 'submit',
      '#value' => t('Save & Edit'),
      '#submit' => array('catalyst_admin_save_edit_submit'),
      '#save_edit' => $save_edit_forms[$base_form_id],
    );
  }
}

/**
 * Save & Edit submit handler.
 */
function catalyst_admin_save_edit_submit($form, &$form_state) {
  $save_edit = $form_state['triggering_element']['#save_edit'];
  $save_edit['submit callback']($form, $form_state);
  if ($redirect = $save_edit['redirect callback']($form, $form_state)) {
    if (isset($_REQUEST['destination'])) {
      $form_state['redirect'] = url($redirect, array(
        'query' => array(
          'destination' => $_REQUEST['destination'],
        ),
        'absolute' => TRUE,
      ));
      $_GET['destination'] = $form_state['redirect'];
      unset($_REQUEST['destination']);
    }
    else {
      // just go back to the form edit page, and dont worry about the redirect
      $form_state['redirect'] = $redirect;
    }
  }
}

/**
 * Save & Edit redirect handler for node forms.
 */
function node_form_save_edit_redirect($form, $form_state) {
  if ($form_state['nid']) {
    return 'node/' . $form_state['nid'] . '/edit';
  }
}

/**
 * Save & Edit redirect handler for eck entities.
 */
function eck__entity_form__redirect($form, $form_state) {
  if (isset($form['#entity_type'], $form['#entity']->type, $form['#entity']->id)) {
    $crud_info = get_bundle_crud_info($form['#entity_type'], $form['#entity']->type);
    return str_replace('%eckentity', $form['#entity']->id, $crud_info['edit']['path']);
  }
}
