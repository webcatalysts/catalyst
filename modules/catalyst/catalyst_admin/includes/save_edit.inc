<?php

/**
 * Implements hook_form_alter().
 */
function catalyst_save_edit_form_alter(&$form, &$form_state, $form_id) {
  if (!isset($form_state['build_info']['base_form_id'])) {
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
      '#submit' => array('catalyst_save_edit_submit'),
      '#save_edit' => $save_edit_forms[$base_form_id],
    );
  }
}

/**
 * Submit redirect handler.
 */
function catalyst_save_edit_submit($form, &$form_state) {
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

function node_form_save_edit_redirect($form, $form_state) {
  if ($form_state['nid']) {
    return 'node/' . $form_state['nid'] . '/edit';
  }
}

function eck__entity_form__redirect($form, $form_state) {
  if (isset($form['#entity_type'], $form['#entity']->type, $form['#entity']->id)) {
    return implode('/', array(
      eck__entity_type__path(),
      $form['#entity_type'],
      $form['#entity']->type,
      $form['#entity']->id,
      'edit',
    ));
  }
}
