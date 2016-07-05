<?php

/**
 * @file
 * Page related functionality. Currently implemented via field__menu which is
 * a serialized field for unstructured storage.
 *
 * Using a specific field (field__menu) to quickly find items which define
 * menu items.
 *
 * @see catalyst_core_form_alter()
 */

function catalyst_menu_widget_form_alter(&$form, &$form_state) {
  $html_id = drupal_html_id(__FUNCTION__);

  $entity = $form['#entity'];
  $entity_type = $form['#entity_type'];
  $bundle = $form['#bundle'];
  $wrapper = entity_metadata_wrapper($entity_type, $entity);
  $language = $form['field__menu']['#language'];
  $field_instance = field_info_instance($entity_type, 'field__menu', $bundle);
  if (isset($form_state['values']['field__menu'][$language][0]['value'])) {
    $values = $form_state['values']['field__menu'][$language][0]['value'];
  }
  else {
    $values = entity_valval($wrapper->field__menu);
  }

  $form['field__menu'][$language][0]['value'] = catalyst_menu_widget($field_instance, $values);
  $form['#submit'][] = 'catalyst_menu_widget_submit';
}

function catalyst_menu_widget_submit($form, &$form_state) {
  variable_set('menu_rebuild_needed', TRUE);
}

function catalyst_menu_widget($field_instance, $values = array()) {
  $html_id = drupal_html_id(__FUNCTION__);
  $widget = array(
    // Provide a wrapper for AJAX
    '#prefix' => '<div id="' . $html_id . '" class="' . drupal_html_class(__FUNCTION__) . '">',
    '#suffix' => '</div>',
    '#validate' => array('catalyst_menu_widget_validate'),
    '#attached' => array(
      'css' => array(catalyst_get_path() . '/css/catalyst-menu-widget.css'),
    ),
  );
  $ajax = array(
    'callback' => 'catalyst_menu_widget_ajax',
    'wrapper' => $html_id,
    'method' => 'replace',
    'effect' => 'fade',
  );
  $widget['path'] = array(
    '#title' => t('Path'),
    '#type' => 'textfield',
    '#default_value' => isset($values['path']) ? $values['path'] : NULL,
    '#required' => $field_instance['required'],
  );
  $widget['menu'] = array(
    '#type' => 'fieldset',
    '#title' => t('Menu options'),
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#tree' => TRUE, // must tree or define array_parents
    '#theme' => 'catalyst_menu_widget_menu_options',
  );
  $widget['menu']['type'] = array(
    '#title' => t('Type'),
    '#type' => 'radios',
    '#options' => array(
      'none' => t('No menu entry'),
      'normal' => t('Normal menu entry'),
      'tab' => t('Menu tab'),
      'default tab' => t('Default menu tab'),
    ),
    '#required' => $field_instance['required'],
    '#default_value' => isset($values['menu']['type']) ? $values['menu']['type'] : NULL,
    '#ajax' => $ajax,
  );
  $options_access = FALSE;
  $parent_access = FALSE;
  if (!empty($values['menu']['type'])) {
    $widget['menu']['#title'] = t('!title - (@type)' , array(
      '@type' => $widget['menu']['type']['#options'][$values['menu']['type']],
      '!title' => $widget['menu']['#title'],
    ));
    $options_access = $values['menu']['type'] != 'none';
    $parent_access = $values['menu']['type'] == 'default tab';
  }
  $widget['menu']['title'] = array(
    '#title' => t('Title'),
    '#description' => t('If set to normal or tab, enter the text to use for the menu item.'),
    '#type' => 'textfield',
    '#default_value' => isset($values['menu']['title']) ? $values['menu']['title'] : NULL,
    '#access' => $options_access,
  );
  $widget['menu']['description'] = array(
    '#title' => t('Description'),
    '#description' => t("If set to normal or tab, enter the text to use for the menu item's description."),
    '#type' => 'textfield',
    '#default_value' => isset($values['menu']['description']) ? $values['menu']['description'] : NULL,
    '#access' => $options_access,
  );
  $widget['menu']['name'] = array(
    '#title' => t('Menu'),
    '#type' => 'select',
    '#options' => menu_get_menus(),
    '#description' => t('Insert item into an available menu.'),
    '#default_value' => isset($values['menu']['name']) ? $values['menu']['name'] : NULL,
    '#access' => $options_access,
  );
  $widget['menu']['weight'] = array(
    '#title' => t('Weight'),
    '#description' => t('The lower the weight the higher/further left it will appear.'),
    '#type' => 'textfield',
    '#default_value' => isset($values['menu']['weight']) ? $values['menu']['weight'] : NULL,
    '#access' => $options_access,
  );
  $widget['menu']['parent'] = array(
    '#type' => 'fieldset',
    '#title' => t('Default tab options'),
    '#access' => $parent_access,
  );
  $widget['menu']['parent']['type'] = array(
    '#type' => 'radios',
    '#title' => t('Parent menu item'),
    '#options' => array(
      'none' => t('Already exists'),
      'normal' => t('Normal menu item'),
      'tab' => t('Menu tab'),
    ),
    '#default_value' => isset($values['menu']['parent']['type']) ? $values['menu']['parent']['type'] : 'none',
    '#ajax' => $ajax,
  );
  $widget['menu']['parent']['title'] = array(
    '#type' => 'textfield',
    '#title' => t('Title'),
    '#description' => t('If creating a parent menu item, enter the title of the item.'),
    '#default_value' => isset($values['menu']['parent']['title']) ? $values['menu']['parent']['title'] : NULL,
    '#access' => $parent_access && $values['menu']['parent']['type'] != 'none',
  );
  $widget['menu']['parent']['description'] = array(
    '#type' => 'textfield',
    '#title' => t('Description'),
    '#description' => t('If creating a parent menu item, enter the description of the item.'),
    '#default_value' => isset($values['menu']['parent']['description']) ? $values['menu']['parent']['description'] : NULl,
    '#access' => $parent_access && $values['menu']['parent']['type'] != 'none',
  );
  $widget['menu']['parent']['weight'] = array(
    '#title' => t('Weight'),
    '#type' => 'textfield',
    '#default_value' => isset($values['menu']['parent']['weight']) ? $values['menu']['parent']['weight'] : 0,
    '#access' => $parent_access && $values['menu']['parent']['type'] != 'none',
  );
  return $widget;
}

function catalyst_menu_widget_ajax($form, &$form_state) {
  $entity = $form['#entity'];
  $language = $form['field__menu']['#language'];
  $type = $form_state['values']['field__menu'][$language][0]['value']['menu']['type'];
  if ($type != 'none') {
    $widget = &$form['field__menu'][$language][0]['value'];
    $widget['menu']['#collapsed'] = FALSE;
    if ($idx = array_search('collapsed', $widget['menu']['#attributes']['class'])) {
      unset($widget['menu']['#attributes']['class'][$idx]);
    }
  }
  return $form['field__menu'][$language][0]['value'];
}

function catalyst_menu_widget_menu_alter(&$menu_items) {
  foreach (catalyst_menu_widget_get_entities() AS $entity) {
    $value = entity_valval($entity->field__menu);
    $path = preg_replace('/(\@[a-z\_]+)/i', '%', $value['path']);
    $menu_options = $value['menu'];
    $parent_options = $value['menu']['parent'];

    $base_item = array(
      'title' => $menu_options['title'],
      'page callback' => 'catalyst_menu_page_callback',
      'page arguments' => array($entity->type(), $entity->getIdentifier()),
      'access callback' => 'catalyst_menu_access_callback',
      'access arguments' => array($entity->type(), $entity->getIdentifier()),
      'title callback' => 'catalyst_menu_title_callback',
      'title arguments' => array($entity->type(), $entity->getIdentifier()),
      'file path' => catalyst_get_path() . '/includes',
      'file' => 'menu_widget.inc',
      'weight' => $menu_options['weight'] != "" ? $menu_options['weight'] : 0,
    );
    switch ($menu_options['type']) {
      case 'normal':
        $menu_items[$path] = array(
          'type' => MENU_NORMAL_ITEM,
        ) + $base_item;
        break;
      case 'tab':
        $menu_items[$path] = array(
          'type' => MENU_LOCAL_TASK,
        ) + $base_item;
        break;
      case 'default tab':
        switch ($menu_options['parent']['type']) {
          case 'none':
            $menu_items[$path] = array(
              'type' => MENU_DEFAULT_LOCAL_TASK,
            ) + $base_item;
            break;
          case 'tab':
          case 'normal':
            $parent_weight = $parent_options['weight'] != "" ? $parent_options['weight'] : 0;
            $parent_path = dirname($path);
            $menu_items[$parent_path] = array(
              'title' => $menu_options['parent']['title'],
              'title callback' => 'catalyst_menu_parent_title_callback',
              'type' => $menu_options['parent']['type'] == 'tab' ? MENU_LOCAL_TASK : MENU_NORMAL_ITEM,
              'weight' => $parent_weight,
            ) + $base_item;
            $menu_items[$path] = array(
              'title' => $menu_options['title'],
              'title callback' => 'catalyst_menu_title_callback',
              'title arguments' => array($entity->type(), $entity->getIdentifier()),
              'type' => MENU_DEFAULT_LOCAL_TASK,
              'weight' => $base_item['weight'],
            );
            /*
            dsm('item: ' . $path);
            dsm($menu_items[$path]);
            dsm('parent: ' . $parent_path);
            dsm($menu_items[$parent_path]);
             */
            break;
        }
        break;
    }
  }
}

function catalyst_menu_widget_get_entities() {
  $query = new EntityFieldQuery;
  $query->fieldCondition('field__menu', 'value_serialized', 'NULL', '!=');
  $entities = array();
  $results = $query->execute();
  foreach ($results AS $entity_type => $result) {
    $loaded = entity_load($entity_type, array_keys($result));
    foreach ($loaded AS $entity) {
      $entities[] = entity_metadata_wrapper($entity_type, $entity);
    }
  }
  return $entities;
}
