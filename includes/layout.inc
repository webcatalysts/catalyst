<?php

/**
 * @file
 */

function catalyst_layout_initialize() {
  global $catalyst_layout;
  if (!isset($catalyst_layout)) {
    // Load the default layout
    //die('No layout set');
    $query = new EntityFieldQuery;
    $query->entityCondition('entity_type', 'catalyst')
      ->entityCondition('bundle', 'layout')
      ->range(0, 1);
    $result = $query->execute();
    if (isset($result['catalyst'])) {
      $layout = array_unshift($result['catalyst']);
      catalyst_set_layout($layout);
    }
  }
}

function catalyst_set_layout($layout) {
  global $catalyst_layout;

  if (!is_object($layout)) {
    $layouts = entity_load('catalyst', $layout);
    $layout = array_pop($layouts);
  }

  $catalyst_layout = entity_metadata_wrapper('catalyst', $layout);
}

