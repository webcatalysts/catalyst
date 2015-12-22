<?php

/**
 * @file
 * Page callbacks for catalyst doctype.
 */

/**
 * Page callback for previewing a doctype.
 */
function catalyst_doctype_preview_page($doctype, $layout, $page) {

  drupal_exit();
}

/**
 * Initial form callback for doctype preview.
 */
function catalyst_doctype_preview_form($form, &$form_state, $doctype) {
  // Since this form is defined in an include file, make sure the form knows it
  form_load_include($form_state, 'pages.inc', 'catalyst_doctype');

  $doctype = entity_metadata_wrapper('catalyst', $doctype);

  $form['#doctype'] = $doctype;

  $form['heading'] = array(
    '#type' => 'markup',
    '#markup' => '<h3>' . t('Configure preview') . '</h3>',
  );

  $layout_options = _doctype_preview_layout_options();
  $form['layout'] = array(
    '#type' => 'select',
    '#title' => t('Select a layout'),
    '#options' => array('') + $layout_options,
    /*
    '#ajax' => array(
      'callback' => 'catalyst_doctype_preview_form_ajax_callback',
      'method' => 'replace',
      'effect' => 'fade',
    ),
     */
  );
  $page_options = _doctype_preview_page_options();
  $form['page'] = array(
    '#type' => 'select',
    '#title' => t('Preview page'),
    '#options' => array('') + $page_options,
  );

  $form['preview_content'] = array(
    '#type' => 'textarea',
    '#title' => t('Preview content'),
  );
  $form['actions'] = array(
    '#type' => 'actions',
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Generate preview'),
  );
  return $form;
}

function catalyst_doctype_preview_form_validate(&$form, &$form_state) {
}

function catalyst_doctype_preview_form_submit(&$form, &$form_state) {

  if ($page_id = $form_state['values']['page']) {
    menu_set_item
    print menu_execute_active_handler('node/' . $page_id);
  }
  elseif ($layout_id = $form_state['values']['layout']) {
    $page = element_info('layout');
    $layout = entity_load_single('catalyst', $layout_id);
    catalyst_set_layout($layout);
    foreach (module_implements('page_build') AS $module) {
      $function = $module . '_page_build';
      $function($page);
    }
    print drupal_render($page);
  }
  else {
    $variables = array(
      '#type' => 'layout',
      '#theme' => 'layout',
      'page' => array(
        '#layout' => NULL,
        '#doctype' => $form['#doctype'],
      ),
    );
    $variables['page']['#children'] = $form_state['values']['preview_content'];
    print theme('doctype', $variables);
  }
  drupal_exit();
}
function catalyst_doctype_preview_form_ajax_callback($form, $form_state) {
  return $form;
}

function _doctype_preview_layout_options() {
  $pref = t('Preferred');
  $other = t('Other');
  $options = array();
  if ($layouts = entity_load('catalyst', FALSE, array('type' => 'layout'))) {
    foreach ($layouts AS $layout) {
      $options[$layout->id] = $layout->title;
    }
  }
  return $options;
}

function _doctype_preview_page_options() {
  $options = array();
  if ($pages = entity_load('node', FALSE, array('type' => 'cpage'))) {
    foreach ($pages AS $page) {
      $options[$page->nid] = $page->title;
    }
  }
  return $options;
}
