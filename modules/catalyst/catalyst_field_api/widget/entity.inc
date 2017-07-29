<?php

/**
 * @file
 * Element handlers for the block placement block widget.
 */

function block_placement_entity_widget_form(&$form, &$form_state, $field, $instance, $langcode, $items, $delta, $element) {
  $values = block_placement_widget_values($element, $items, $form_state);

  $layout_options = block_placement_entity_layout_options();
  if (empty($layout_options)) {
    $element['#theme'] = 'block_placement_entity_widget_no_layouts';
    return $element;
  }

  $element['#theme'] = 'block_placement_entity_widget';
  $element['#prefix'] = '<div id="block-placement-entity--' . $delta . '">';
  $element['#suffix'] = '</div>';
  $ajax = array(
    'callback' => 'block_placement_entity_widget_ajax_callback',
    'method' => 'replace',
    'wrapper' => 'block-placement-entity--' . $delta,
    'effect' => 'fade',
    'field_name' => $instance['field_name'],
    'langcode' => $langcode,
    'delta' => $delta,
  );
  $element['block_id'] = array(
    '#type' => 'select',
    '#title' => t('Block'),
    '#options' => array('') + block_placement_widget_block_options(),
    '#default_value' => $values['block_id'],
  );
  $element['layout_id'] = array(
    '#type' => 'select',
    '#title' => t('Layout'),
    '#options' => array('') + $layout_options,
    '#default_value' => $values['layout_id'],
    '#ajax' => $ajax,
  );
  $element['region'] = array(
    '#type' => 'select',
    '#title' => t('Region'),
    '#options' => array('') + block_placement_widget_region_options($values['layout_id'], $langcode),
    '#default_value' => $values['region'],
    '#ajax' => $ajax,
  );
  $element['weight'] = array(
    '#type' => 'select',
    '#title' => t('Weight'),
    '#options' => array_combine(range(-50,50),range(-50,50)),
    '#default_value' => empty($values['weight']) ? 0 : $values['weight'],
  );
  $element['visibility'] = array(
    '#type' => 'value',
    '#value' => 0,
  );
  $element['cache'] = array(
    '#type' => 'value',
    '#value' => 0,
  );
  $element['#after_build'][] = 'block_placement_entity_widget_after_build';
  return $element;
}

function block_placement_entity_widget_ajax_callback($form, $form_state) {
  $info = $form_state['triggering_element']['#ajax'];
  return $form[$info['field_name']][$info['langcode']][$info['delta']];
}

/**
 * Retrieves only layouts that have regions defined as options.
 */
function block_placement_entity_layout_options() {
  $options = &drupal_static(__FUNCTION__);
  if (!isset($options)) {
    $options = array();
    $query = new EntityFieldQuery;
    $query->entityCondition('entity_type', 'catalyst')
      ->entityCondition('bundle', 'layout')
      ->fieldCondition('field__layout_regions', 'machine', 'NULL', '!=')
      ->addTag(__FUNCTION__);
    $result = $query->execute();
    if (isset($result['catalyst'])) {
      $layouts = entity_load('catalyst', array_keys($result['catalyst']));
      foreach ($layouts AS $layout) {
        $layout = entity_metadata_wrapper('catalyst', $layout);
        $options[$layout->getIdentifier()] = $layout->label();
      }
    }
  }
  return $options;
}

/**
 * Improve usability of the widget by hidding the fields that are
 * not relevant until requisite fields are completed.
 */
function block_placement_entity_widget_after_build($element) {
  if (count($element['region']['#options']) <= 1) {
    $element['region']['#access'] = FALSE;
  }
  if (empty($element['region']['#default_value'])) {
    $element['weight']['#access'] = FALSE;
  }
  $element['_weight']['#access'] = FALSE;
  return $element;
}

/**
 * Theme a block placement block widget
 */
function theme_block_placement_entity_widget(&$variables) {
  $output = '<div class="container-inline">' . "\n"
          . drupal_render($variables['element']['block_id']) . "\n"
          . drupal_render($variables['element']['layout_id']) . "\n"
          . drupal_render($variables['element']['region']) . "\n"
          . drupal_render($variables['element']['weight']) . "\n"
          . '</div>' . "\n";
  return $output . drupal_render($variables['element']['pages']);
}

function theme_block_placement_entity_field_container_no_layouts($variables) {
  return drupal_render($variables['element']['_ajax']) . "\n"
    . '<p>' .  t('No layouts (with regions) exist.') . '</p>';
}
function theme_block_placement_entity_field_container_no_blocks($variables) {
  return '<p>' .  t('No blocks exist.') . '</p>';
}
