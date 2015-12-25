<?php

/**
 * @file
 */

function catalyst_layout_initialize() {
  global $catalyst_layout;
  if (!isset($catalyst_layout)) {
    if ($default = variable_get('catalyst_layout_default', FALSE)) {
      catalyst_set_layout($default);
    }
    else {
      catalyst_set_layout(2);
    }
  }
}

function catalyst_set_layout($layout) {
  global $catalyst_layout;

  if (!is_object($layout)) {
    $layouts = entity_load('catalyst', array($layout));
    $layout = array_pop($layouts);
  }

  $catalyst_layout = entity_metadata_wrapper('catalyst', $layout);
}

