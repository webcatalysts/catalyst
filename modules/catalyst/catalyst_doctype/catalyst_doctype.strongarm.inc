<?php
/**
 * @file
 * catalyst_doctype.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function catalyst_doctype_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_catalyst__doctype';
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
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '21',
        ),
      ),
      'display' => array(
        'title' => array(
          'default' => array(
            'weight' => '0',
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
  $export['field_bundle_settings_catalyst__doctype'] = $strongarm;

  return $export;
}
