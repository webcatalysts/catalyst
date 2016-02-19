<?php

/**
 * @file
 * Package related functions and callbacks for Catalyst Core.
 */

function catalyst_update_package($entity, $context) {
  $package = $context['package'];
  $wrapper = entity_metadata_wrapper($context['entity_type'], $entity);
  $wrapper->field__package->set($package);

  $package_title = empty($package) ? t('No package') : filter_xss_admin($package->title);

  if ($wrapper->save()) {
    watchdog('action', 'Updated @entity_title\'s package to @package_title', array(
      '@entity_title' => $wrapper->label(),
      '@package_title' => $package_title,
    ));
  }
  else {
    watchdog('error', 'Unable to update @entity_title\'s to @package_title', array(
      '@entity_title' => $wrapper->label(),
      '@package_title' => $package_title,
    ));
  }
}

function catalyst_update_package_form($context) {
  $args = func_get_args();
  $package_options = array();
  $packages = catalyst_load('package');
  foreach ($packages AS $package) {
    $package_options[$package->id] = filter_xss_admin($package->title);
  }
  $form['package_id'] = array(
    '#type' => 'select',
    '#title' => t('Package'),
    '#options' => array('' => t('No package')) + $package_options,
  );
  $form['entity_type'] = array(
    '#type' => 'hidden',
    '#value' => $context['entity_type'],
  );
  return $form;
}

function catalyst_update_package_form_submit($form, $form_state) {
  $package_id = $form_state['values']['package_id'];
  $package = empty($package_id) ? NULL : catalyst_load_single($package_id);
  return array(
    'package' => $package,
    'entity_type' => $form_state['values']['entity_type'],
  );
}
