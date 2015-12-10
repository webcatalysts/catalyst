<?php

function notheme_field($variables) {
  $output = '';
  foreach ($variables['items'] AS $item) {
    $output .= drupal_render($item) . "\n";
  }
  return $output;
}
