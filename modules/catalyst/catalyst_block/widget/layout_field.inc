<?php

/**
 * Block placement widget with an "alternate" layout field.
 *
 * The alternate layout field presently is hard coded but is a seperate field.
 */
function block_placement_layout_field_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  // Spoof configurable settings
  $instance['settings']['layout_field_name'] = 'field_cpage_layout';

  if (!isset($form['#block_placement'])) {
    $form['#block_placement'] = array(
      'widget_field_name' => $instance['field_name'],
      'layout_field_name' => $instance['settings']['layout_field_name'],
      'layout_field_ajax' => array(
        'callback' => 'block_placement_layout_field_widget_ajax_callback',
        'method' => 'replace',
        'effect' => 'fade',
        'wrapper' => 'block-placement-layout-field-wrapper',
        'trigger_as' => array(
          'name' => $instance['field_name'] . '[_ajax]',
        ),
      ),
      'layout_id' => NULL,
      'regions' => NULL,
    );
  }

  // Process the entire form when we have access to the layout field
  $form['#process'][] = 'block_placement_layout_field_widget_form_process';

  return $element += array(
    '#item_values' => isset($items[$delta]) ? $items[$delta] : array(),
    '#process' => array('block_placement_layout_field_widget_process'),
  );
}

function block_placement_layout_field_widget_process($element, &$form_state, &$form) {
  if ($regions = $form['#block_placement']['regions']) {
    $values = $element['#item_values'] += array(
      'region' => NULL,
      'block_id' => NULL,
      'weight' => 0,
      'cache' => 0,
    );
    $element['block_id'] = array(
      '#type' => 'select',
      '#title' => t('Block'),
      '#options' => array('') + block_placement_widget_block_options(),
      '#default_value' => $values['block_id'],
    );
    $element['region'] = array(
      '#type' => 'select',
      '#title' => t('Regions'),
      '#options' => array('') + block_placement_widget_region_options($form['#block_placement']['layout_id']),
      '#default_value' => $values['region'],
    );
    $element['weight'] = array(
      '#type' => 'select',
      '#title' => t('Weight'),
      '#options' => block_placement_widget_weight_options(),
      '#default_value' => $values['weight'],
    );
    $element['cache'] = array(
      '#type' => 'value',
      '#value' => 0,
    );
    $element['#theme'] = 'block_placement_layout_field_widget';
  }
  return $element;
}

function block_placement_layout_field_widget_layout_field_process($element, &$form_state, $form) {
  $element['#ajax'] = $form['#block_placement']['layout_field_ajax'];
  $element = ajax_process_form($element, $form_state);
  return $element;
}

function block_placement_layout_field_widget_form_process($form, &$form_state, $context) {
  $layout_field_name = $form['#block_placement']['layout_field_name'];

  // There is no alt layout on the field configuration form
  if (isset($form[$layout_field_name])) {
    $lang = $form[$layout_field_name]['#language'];
    $layout_field = &$form[$layout_field_name][$lang];
    $layout_field['#process'][] = 'block_placement_layout_field_widget_layout_field_process';

    $widget_field_name = $form['#block_placement']['widget_field_name'];
    $widget_container = &$form[$widget_field_name];

    // Wrap the entire field (all elements) with the AJAX wrapper
    $widget_container['#prefix'] = '<div id="block-placement-layout-field-wrapper">';
    $widget_container['#suffix'] = '</div>';
    $widget_container['_ajax'] = array(
      '#type' => 'checkbox',
      '#attributes' => array('class' => array('element-hidden')),
      '#ajax' => $form['#block_placement']['layout_field_ajax'],
      '#has_garbage_value' => TRUE,
    );

    $layout_id = $layout_field['#default_value'][0];
    if (!empty($form_state['input'][$layout_field_name])) {
      $layout_id = $form_state['input'][$layout_field_name][$lang];
    }
    if ($layout_id) {
      $form['#block_placement']['has_layout'] = $layout_id;
      $form['#block_placement']['layout_id'] = $layout_id;

      if ($regions = block_placement_widget_region_options($layout_id, $lang)) {
        $form['#block_placement']['regions'] = $regions;
      }
      else {
        $widget_container['#theme'] = 'block_placement_layout_field_container_no_regions';
      }
    }
    else {
      $widget_container['#theme'] = 'block_placement_layout_field_container_no_layout';
    }
  }
  return $form;
}

function block_placement_layout_field_widget_ajax_callback($form, $form_state) {
  $field_name = $form['#block_placement']['widget_field_name'];
  return $form[$field_name];
}

function theme_block_placement_layout_field_widget($variables) {
  return '<div class="container-inline">' . "\n"
    . drupal_render($variables['element']['block_id']) . "\n"
    . drupal_render($variables['element']['region']) . "\n"
    . drupal_render($variables['element']['weight']) . "\n"
    . '</div>';
}

function theme_block_placement_layout_field_container_no_layout($variables) {
  return drupal_render($variables['element']['_ajax']) . "\n"
    . '<p>' .  t('No layout has been selected.') . '</p>';
}
function theme_block_placement_layout_field_container_no_regions($variables) {
  return '<p>' .  t('The selected layout has no regions.') . '</p>';
}
