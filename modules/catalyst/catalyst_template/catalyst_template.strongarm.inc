<?php
/**
 * @file
 * catalyst_template.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function catalyst_template_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_catalyst__template';
  $strongarm->value = array(
    'view_modes' => array(),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '0',
        ),
      ),
      'display' => array(
        'title' => array(
          'template' => array(
            'weight' => '0',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_catalyst__template'] = $strongarm;

  return $export;
}
