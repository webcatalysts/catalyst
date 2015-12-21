<?php

/**
 * @file
 */

function catalyst_layout_initialize() {
  global $catalyst_layout;
  if (!isset($catalyst_layout)) {
    catalyst_set_layout(variable_get('catalyst_layout_default', 163));
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

