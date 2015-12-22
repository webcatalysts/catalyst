<?php

/**
 * @file
 * Functions for the block placement layout widget.
 */

/**
 * Base form handler for the block placement layout widget.
 */
function block_placement_layout_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  $instance['settings']['regions_field_name'] = 'field_layout_regions';

  $form['#block_placement'] = array(
    'widget_field_name' => $instance['field_name'],
    'regions_field_name' => $instance['settings']['regions_field_name'],
    'ajax' => array(
      'callback' => 'block_placement_layout_widget_ajax_callback',
      'wrapper' => 'block-placement-layout-widget-wrapper',
      'method' => 'replace',
      'trigger_as' => array('name' => $instance['field_name'] . '[_ajax]'),
    ),
    'regions' => FALSE,
  );
  $form['#process'][] = 'block_placement_layout_widget_form_process';

  return $element += array(
    '#process' => array('block_placement_layout_widget_process'),
    '#item_values' => block_placement_widget_values($element, $items, $form_state),
  );
}

/**
 * Process each block placement layout widget.
 *
 * This is called after the form processing is done.
 */
function block_placement_layout_widget_process($element, &$form_state, &$form) {
  if ($form['#block_placement']['regions']) {
    $values = $element['#item_values'];
    $element['block_id'] = array(
      '#type' => 'select',
      '#title' => t('Block'),
      '#options' => array('') + block_placement_widget_block_options(),
      '#default_value' => $values['block_id'],
      '#ajax' => $form['#block_placement']['ajax']
    );
    $element['region'] = array(
      '#type' => 'select',
      '#title' => t('Region'),
      '#options' => array('') + $form['#block_placement']['regions'],
      '#default_value' => $values['region'],
      '#ajax' => $form['#block_placement']['ajax']
    );
    $element['weight'] = array(
      '#type' => 'select',
      '#title' => t('Weight'),
      '#options' => block_placement_widget_weight_options(),
      '#default_value' => $values['weight'],
    );
    $element['visibility'] = array(
      '#type' => 'select',
      '#title' => t('Visibility'),
      '#options' => block_placement_widget_visibility_options(),
      '#default_value' => $values['visibility'],
      '#ajax' => $form['#block_placement']['ajax']
    );
    $element['pages'] = array(
      '#type' => 'textarea',
      '#title' => t('Pages'),
      '#default_value' => $values['pages'],
    );
    $element['cache'] = array(
      '#type' => 'value',
      '#default_value' => 0, //$values['cache'],
    );
    $element['#theme'] = 'block_placement_layout_widget';
    $element['#validate'][] = 'block_placement_layout_widget_validate';
    $element['#after_build'][] = 'block_placement_layout_widget_after_build';
  }
  return $element;
}

/**
 * Process handler for the external region field container.
 *
 * Applies AJAX to each region element's text and machine field.
 */
function block_placement_layout_widget_region_element_process($element, &$form_state, &$form) {
  $element['#ajax'] = $form['#block_placement']['ajax'];
  $element = ajax_process_form($element, $form_state);
  return $element;
}

/**
 * Process the entire form of a block placement layout widget.
 *
 * Applies AJAX on external elements, determines region values, and adds
 * processing to the widget and region element when applicable.
 */
function block_placement_layout_widget_form_process($form, &$form_state, $context) {
  $regions_field_name = $form['#block_placement']['regions_field_name'];
  // No regions field on field configuration form
  if (isset($form[$regions_field_name])) {
    $lang = $form[$regions_field_name]['#language'];
    $regions_container = &$form[$regions_field_name];

    $widget_field_name = $form['#block_placement']['widget_field_name'];
    $widget_container = &$form[$widget_field_name];
    $widget_container['#prefix'] = '<div id="block-placement-layout-widget-wrapper">';
    $widget_container['#suffix'] = '</div>';
    $widget_container['_ajax'] = array(
      '#has_garbage_value' => TRUE,
      '#type' => 'checkbox',
      '#ajax' => $form['#block_placement']['ajax'],
      '#attributes' => array('class' => array('element-invisible')),
    );

    $regions = array();
    // Add ajax to each region's text and machine field
    foreach (element_children($regions_container[$lang]) AS $i) {
      if (isset($regions_container[$lang][$i]['text'])) {
        $regions_container[$lang][$i]['text']['#process'][] = 'block_placement_layout_widget_region_element_process';
        //$regions_container[$lang][$i]['machine']['#process'][] = 'block_placement_layout_widget_regions_container_process';
        if (!empty($regions_container[$lang][$i]['machine']['#default_value'])) {
          $machine = $regions_container[$lang][$i]['machine']['#default_value'];
          $text = $regions_container[$lang][$i]['text']['#default_value'];
          $regions[$machine] = $text;
        }
      }
    }

    if (isset($form_state['input'][$regions_field_name])) {
      $regions = array();
      foreach ($form_state['input'][$regions_field_name][$lang] AS $region) {
        if (!empty($region['machine']) && !empty($region['text'])) {
          $regions[$region['machine']] = $region['text'];
        }
      }
    }
    $form['#block_placement']['regions'] = $regions;
  }
  return $form;
}

function block_placement_layout_widget_after_build($element, &$form_state) {
  $values = $element['#item_values'];
  $hide = array();
  if (empty($values['block_id'])) {
    $element['block_id']['#title'] = t('Add block');
    $hide = array('region', 'weight', 'visibility', 'pages');
  }
  elseif (empty($values['region'])) {
    $element['region']['#title'] = t('Select a region');
    $hide = array('weight', 'visibility', 'pages');
  }
  elseif (!$values['visibility']) {
    $hide = array('pages');
  }
  foreach ($hide AS $key) {
    hide($element[$key]);
  }
  return $element;
}

function theme_block_placement_layout_widget($variables) {
  return '<div class="container-inline">' . "\n"
    . drupal_render($variables['element']['block_id']) . "\n"
    . drupal_render($variables['element']['region']) . "\n"
    . drupal_render($variables['element']['weight']) . "\n"
    . drupal_render($variables['element']['visibility']) . "\n"
    . '</div>' . "\n"
    . drupal_render($variables['element']['pages']) . "\n";
}

function theme_block_placement_layout_container_no_regions($variables) {
  return '<p>' . t('The layout has no regions defined. Add regions before adding blocks.') . '</p>';
}

/**
 * Validation of a block placement layout element.
 */
function block_placement_layout_widget_validate($element, &$form_state, $form) {
  // @todo Add validation to warn of partial block placements
}

/**
 * AJAX callback for the block placement widget.
 *
 * @todo This could be moved to common.inc
 */
function block_placement_layout_widget_ajax_callback($form, $form_state) {
  $widget_field_name = $form['#block_placement']['widget_field_name'];
  return $form[$widget_field_name];
}
