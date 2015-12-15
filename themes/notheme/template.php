<?php

function notheme_field($variables) {
  $output = '';
  foreach ($variables['items'] AS $item) {
    $output .= drupal_render($item) . "\n";
  }
  return $output;
}

/**
function notheme_html($variables) {
  return '';
}

function notheme_page($variables) {
  print $variables['messages'];
}
**/
