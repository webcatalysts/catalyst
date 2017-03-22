<?php

/**
 * @file
 * Theme functions for Catalyst Core.
 */

/**
 *
 */
function theme_catalyst_template($variables) {
  $variables = catalyst_template_collect_variables($variables['theme_original'], $variables['element_original']) + $variables;

  if ($preprocess_php = $variables['template']->getPreprocessPHP()) {
    catalyst_eval($preprocess_php, $variables);
  }

  return $variables['template']->renderTemplate($variables);
}


function catalyst_template_collect_variables($theme_hook, $element) {
  $theme_registry = theme_get_registry();
  $info = $theme_registry[$theme_hook];
  $variables = array('classes_array' => array());
  if (isset($info['variables'])) {
    foreach (array_keys($info['variables']) AS $name) {
      $variables[$name] = $element["#$name"];
    }
  }
  else {
    $variables[$info['render element']] = $element;
  }

  if (!empty($info['variables'])) {
    $variables += $info['variables'];
  }
  elseif (!empty($info['render element'])) {
    $variables += array($info['render element'] => array());
  }

  $skip = array(
    'template_preprocess',
 //   'template_preprocess_node',
//    'ctools_preprocess_node',
//    'rdf_preprocess_node',
//    'views_preprocess_node',
//    'field_group_build_entity_groups',
  );
  $variables += _template_preprocess_default_variables();
  if (isset($info['preprocess functions']) || isset($info['process functions'])) {
    $variables['theme_hook_suggestions'] = array();
    foreach (array('preprocess functions', 'process functions') as $phase) {
      if (!empty($info[$phase])) {
        foreach ($info[$phase] as $processor_function) {
          //if (function_exists($processor_function)) {
          if (!in_array($processor_function, $skip) && function_exists($processor_function)) {
            $hook_clone = $theme_hook;
            $processor_function($variables, $hook_clone);
          }
        }
      }
    }
  }
  return $variables;
}
