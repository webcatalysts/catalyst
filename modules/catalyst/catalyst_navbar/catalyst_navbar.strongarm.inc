<?php
/**
 * @file
 * catalyst_navbar.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function catalyst_navbar_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shortcutperrole';
  $strongarm->value = array(
    1 => 'shortcut-set-1',
    2 => 'shortcut-set-1',
    6 => 'shortcut-set-1',
    5 => 'shortcut-set-2',
    4 => 'shortcut-set-3',
    7 => 'shortcut-set-1',
    3 => 'shortcut-set-4',
  );
  $export['shortcutperrole'] = $strongarm;

  return $export;
}
