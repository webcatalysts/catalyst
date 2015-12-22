<?php

/**
 * @file
 * Page callbacks and form handlers used by administration pages for menu_lockdown.
 *
 * @see menu_lockdown_menu().
 */

/**
 * Page handler for the menu_lockdown admin debugging page.
 *
 * Checks to ensure menu_lockdown isn't already disabled when debugging
 * is irrelevant.
 */
function menu_lockdown_admin_debug() {
  if (variable_get('menu_lockdown_disabled', FALSE)) {
    return t('Menu lockdown is disabled in code.');
  }
  if ($debug_timeout = menu_lockdown_debug()) {
    drupal_set_message(
      t('Menu lockdown debugging is enabled and will expire at %time.',
        array('%time' => date('g:i A', $debug_timeout))
      )
    );
  }
  return drupal_get_form('menu_lockdown_admin_debug_form');
}

function menu_lockdown_admin_debug_form($form, &$form_state) {
  $form = system_settings_form($form);
  $form['menu_lockdown_debug'] = array(
    '#type' => 'select',
    '#title' => t('Debugging timeout'),
    '#options' => array(
      300 => t('5 minutes'),
      900 => t('15 minutes'),
      1800 => t('30 minutes'),
      3600 => t('1 hour'),
      10800 => t('3 hours'),
      21600 => t('6 hours'),
    ),
  );
  $form['actions']['submit']['#value'] = t('Temporarily disable menu lockdown');
  return $form;
}

function menu_lockdown_admin_debug_form_validate(&$form, &$form_state) {
  $form_state['values']['menu_lockdown_debug'] += time();
}

function menu_lockdown_admin_settings_form($form, &$form_state) {
  $form['#theme'] = 'menu_lockdown_settings';

  // Include CSS and JS for form
  $module_path = drupal_get_path('module', 'menu_lockdown');
  $form['#attached']['css'][] = $module_path . '/menu_lockdown.admin.css';
  $form['#attached']['js'][] = $module_path . '/menu_lockdown.admin.js';
  $form['#attributes']['class'][] = 'menu-lockdown';
   drupal_add_library('system','effects.highlight');

  module_load_include('inc', 'menu_lockdown');
  $whitelist = menu_lockdown_paths(MENU_LOCKDOWN_WHITELIST);
  $blacklist = menu_lockdown_paths(MENU_LOCKDOWN_BLACKLIST);
  $form['menu_lockdown_whitelist'] = array(
    '#type' => 'textarea',
    '#title' => t('Whitelist paths'),
    '#default_value' => implode("\n", $whitelist),
    '#rows' => count($whitelist) > 5 ? count($whitelist) : NULL,
  );
  $form['menu_lockdown_blacklist'] = array(
    '#type' => 'textarea',
    '#title' => t('Blacklist paths'),
    '#default_value' => implode("\n", $blacklist),
    '#rows' => count($blacklist) > 5 ? count($blacklist) : NULL,
  );
  $form['menu_lockdown_warn_disabled'] = array(
    '#title' => t('Display "disabled" warning'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('menu_lockdown_warn_disabled', TRUE) ? 1 : 0,
    '#description' => t('If checked, when menu lockdown is disabled in configuration, as it should be on development environments, a notice message will be displayed on blocklisted pages.'),
  );
  $form['menu_lockdown_warn_debug'] = array(
    '#title' => t('Display "debug" warning'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('menu_lockdown_warn_debug', TRUE) ? 1 : 0,
    '#description' => t('If checked, when menu lockdown debugging is enabled, a notice message will be displayed on blocklisted pages.'),
  );

  $form['widget'] = array(
    '#theme' => 'table',
    '#process' => array('menu_lockdown_widget_process'),
    '#attributes' => array(
      'class' => array('menu-lockdown'),
    ),
  );
  foreach (module_implements('menu') AS $module) {
    if ($menu_items = call_user_func($module . '_menu')) {
      if (!is_array($menu_items)) continue;
      foreach ($menu_items AS $path => $menu_item) {
        if (!menu_lockdown_path_configured($path)) {
          $widget_item = array(
            '#title' => isset($menu_item['title']) ? check_plain($menu_item['title']) : NULL,
            '#path' => check_plain($path),
            '#tree' => FALSE,
          );
          $widget_item['whitelist_add'] = array(
            '#type' => 'radio',
            '#name' => 'list_add[' . $path . ']',
            '#value' => NULL,
            '#return_value' => 'whitelist',
            '#attributes' => array(
              '--data-path' => $path,
            ),
          );
          $widget_item['blacklist_add'] = array(
            '#name' => 'list_add[' . $path . ']',
            '#type' => 'radio',
            '#return_value' => 'blacklist',
            '#value' => NULL,
            '#attributes' => array(
              '--data-path' => $path,
            ),
          );
          $form['widget'][$module][$path] = $widget_item;
        }
      }

      if (isset($form['widget'][$module])) {
        $form['widget'][$module] += array(
          '#tree' => FALSE,
        );
      }
    }
  }
  ksort($form['widget']);
  return system_settings_form($form);
}

function menu_lockdown_widget_process($element) {
  $element['#header'] = array(
    array('data' => t('Path'), 'class' => array('path')),
    array('data' => t('Whitelist'), 'class' => array('whitelist-add')),
    array('data' => t('Blacklist'), 'class' => array('blacklist-add'))
  );
  $element['#rows'] = array();
  $last_module = NULL;
  foreach (element_children($element) AS $module) {
    if ($last_module != $module) {
      $last_module = $module;
      $element['#rows'][] = array(
        'data' => array(array('data' => $module, 'colspan' => 3)),
        'class' => array('module'),
      );
    }
    foreach (element_children($element[$module]) AS $path) {
      $row = array(
        array('data' => $element[$module][$path]['#path'], 'class' => 'path'),
        // Whitelist checkbox cell
        array(
          'data' => drupal_render($element[$module][$path]['whitelist_add']),
          'class' => 'whitelist-add'
        ),
        // Blacklist checkbox cell
        array(
          'data' => drupal_render($element[$module][$path]['blacklist_add']),
          'class' => 'blacklist-add'
        )
      );
      $element['#rows'][] = $row;
    }
    drupal_render($element[$module]);
  }
  return $element;
}

function menu_lockdown_admin_settings_form_validate(&$form, &$form_state) {
  // Create a shortcut reference
  foreach (array('whitelist', 'blacklist') AS $list) {
    $value =& $form_state['values']['menu_lockdown_' . $list];
    $value = explode("\n", $value);
  }
}

function menu_lockdown_path_configured($path) {
  $whitelist = implode("\n", menu_lockdown_paths(MENU_LOCKDOWN_WHITELIST));
  $blacklist = implode("\n", menu_lockdown_paths(MENU_LOCKDOWN_BLACKLIST));
  return drupal_match_path($path, $whitelist) || drupal_match_path($path, $blacklist);
}

