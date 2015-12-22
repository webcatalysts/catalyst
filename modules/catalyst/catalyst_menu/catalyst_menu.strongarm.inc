<?php
/**
 * @file
 * catalyst_menu.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function catalyst_menu_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_menu_order';
  $strongarm->value = array(
    'main-menu' => '',
    'user-menu' => '',
  );
  $export['menu_block_menu_order'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_block_suppress_core';
  $strongarm->value = 0;
  $export['menu_block_suppress_core'] = $strongarm;

  return $export;
}
