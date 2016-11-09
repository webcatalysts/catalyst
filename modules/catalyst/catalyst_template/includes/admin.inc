<?php

/**
 * @file
 * Catalyst template admin page and form callbacks.
 */

function catalyst_template_admin_list() {
  $entity_info = entity_get_info();
  unset($entity_info['catalyst']);
  $build = array();
  foreach ($entity_info  AS $entity_type => $entity_type_info) {
    if (empty($entity_type_info['view modes'])) {
      continue;
    }
    $build[$entity_type] = array(
      '#theme' => 'table',
      '#header' => array(t('Bundle'), t('Actions')),
      '#rows' => array(),
      '#caption' => $entity_type_info['label'],
    );
    $default = array('__default__' => array('label' => t('Default')));
    $bundles = $default + $entity_type_info['bundles'];
    foreach ($bundles AS $bundle => $bundle_info) {
      $links = array();
      if ($template = catalyst_template_load($entity_type, $bundle, FALSE)) {
        $links['configure'] = array(
          'href' =>  'admin/catalyst/template/' . $template->id . '/edit',
          'title' => t('configure'),
        );
        $links['delete'] = array(
          'href' =>  'admin/catalyst/template/' . $template->id . '/delete',
          'title' => t('delete'),
        );
      }
      else {
        $links['configure'] = array(
          'href' =>  'admin/catalyst/template/add/' . $entity_type . '/' . $bundle,
          'title' => t('setup'),
        );
      }
      $build[$entity_type]['#rows'][] = array(
        $bundle_info['label'],
        theme('links', array('links' => $links, 'attributes' => array('class' => array('inline')))),
      );
    }
  }
  return $build;
}

function catalyst_template_admin_add($entity_type, $bundle) {
  $entity_info = entity_get_info($entity_type);
  // Validate the arguments
  if (!$entity_info || ($bundle != '__default__' && !isset($entity_info['bundles'][$bundle]))) {
    return drupal_not_found();
  }

  // Ensure template doesn't already exist
  if ($template = catalyst_template_load($entity_type, $bundle, FALSE)) {
    drupal_goto('admin/catalyst/template/' . $template->id);
  }

  $bundle_label = $bundle == '__default__' ? t('Default') : $entity_info['bundles'][$bundle]['label'];

  drupal_set_title(t('Add @bundle_label (@entity_type_label) template', array(
    '@entity_type_label' => strtolower($entity_info['label']),
    '@bundle_label' => strtolower($bundle_label),
  )));

  $entity = entity_create('catalyst', array('type' => 'template'));
  return drupal_get_form('eck__entity__form_add_catalyst_template', $entity, $entity_type, $bundle);
}

function catalyst_template_add_form_after_build($form, &$form_state) {
  $entity_type = $form_state['build_info']['args'][1];
  $bundle = $form_state['build_info']['args'][2];
  $entity_info = entity_get_info($entity_type);
  $bundle_label = $bundle == '__default__' ? t('Default') : $entity_info['bundles'][$bundle]['label'];
  $form['title']['#value'] = t('@bundle_label (@entity_type_label)', array(
    '@entity_type_label' => $entity_info['label'],
    '@bundle_label' => $bundle_label,
  ));
  $form['field__template_entity_type'][LANGUAGE_NONE][0]['machine']['#value'] = $entity_type;
  $form['field__template_bundle'][LANGUAGE_NONE][0]['machine']['#value'] = $bundle;
  $form['field__machine'][LANGUAGE_NONE][0]['machine']['#value'] = $entity_type . '_' . $bundle;

  return catalyst_template_form_after_build($form, $form_state);
}

function catalyst_template_form_after_build($form, &$form_state) {
  $form['title'] = array(
    '#type' => 'hidden',
    '#value' => $form['title']['#value'],
    '#name' => 'title',
  );
  $form['field__template_entity_type']['#attributes']['class'][] = 'element-hidden';
  $form['field__template_bundle']['#attributes']['class'][] = 'element-hidden';
  $form['field__machine']['#attributes']['class'][] = 'element-hidden';
  return $form;
}
