<?php
/**
 * @file
 * catalyst_layout.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function catalyst_layout_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_catalyst__layout';
  $strongarm->value = array(
    'view_modes' => array(
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'template' => array(
        'custom_settings' => TRUE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '5',
        ),
      ),
      'display' => array(
        'title' => array(
          'default' => array(
            'weight' => '8',
            'visible' => FALSE,
          ),
          'template' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_catalyst__layout'] = $strongarm;

  return $export;
}
