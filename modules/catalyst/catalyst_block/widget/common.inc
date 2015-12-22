<?php

/**
 * @file
 * Common functions utilized by the block placement widgets.
 */

/**
 * Retrieve the layout region options based on the selected layout.
 *
 * This could be shared with other widgets.
 */
function block_placement_widget_region_options($layout, $langcode = LANGUAGE_NONE) {
  $options = array();
  if ($layout) {
    if (!is_object($layout)) {
      $layout = entity_load_single('catalyst', $layout);
    }
    if ($layout->field_layout_regions) {
      foreach ($layout->field_layout_regions[$langcode] AS $region) {
        $options[$region['machine']] = $region['text'];
      }
    }
  }
  return $options;
}

/**
 * Retrieve the block options for block placement widgets.
 */
function block_placement_widget_block_options() {
  $options = &drupal_static(__FUNCTION__);

  if (!isset($options)) {
    $options = array();
    if ($blocks = catalyst_block_load()) {
      foreach ($blocks AS $block) {
        $options[$block->id] = $block->title;
      }
    }
  }
  return $options;
}

/**
 * Retrive the visibility options for block placement widgets.
 */
function block_placement_widget_visibility_options() {
  return array(
    CATALYST_BLOCK_VISIBILITY_ALL => t('Show on all pages'),
    CATALYST_BLOCK_VISIBILITY_ONLY => t('Show on specific pages'),
    CATALYST_BLOCK_VISIBILITY_EXCEPT => t('Show on all pages except specific pages'),
    CATALYST_BLOCK_VISIBILITY_PHP => t('Advanced'),
  );
}

/**
 * Retrive weight options for block placement widgets.
 */
function block_placement_widget_weight_options() {
  $range = range(-50,50);
  return array_combine($range, $range);
}

/**
 * Determine the values for the block placement block element.
 */
function block_placement_widget_values($element, $items, $form_state) {
  $values = array();

  $field_name = $element['#field_name'];
  $lang = $element['#language'];
  $delta = $element['#delta'];
  if (isset($form_state['input'][$field_name][$lang][$delta])) {
    $values = $form_state['input'][$field_name][$lang][$delta];
  }
  elseif (isset($items[$delta])) {
    $values = $items[$delta];
  }
  return $values + array(
    'layout_id' => NULL,
    'block_id' => NULL,
    'region' => NULL,
    'weight' => 0,
    'visibility' => NULL,
    'pages' => NULL,
    'cache' => 0,
  );
}
