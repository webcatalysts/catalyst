<?php

/**
 * @file
 */

/**
 * Custom delivery callback for Catalyst CMS.
 *
 */
function catalyst_deliver_page($page_callback_result) {
  print catalyst_render_page($page_callback_result);
}

/**
 * Custom page renderer for Catalyst CMS.
 *
 * @see drupal_render_page()
 */
function catalyst_render_page($main_content) {
  $page = element_info('layout');
  $page['content'] = $main_content;
  return drupal_render($page);
}

function catalyst_add_css($stylesheet, $group = CATALYST_MEDIA_GROUP_OTHER) {
  $options = array(
    'group' => $group,
    //'media' => $stylesheet->field_stylesheet_media->value(),
    'media' => 'all',
  );

  $options['basename'] = $stylesheet->field_stylesheet_machine->value()['machine'];
  switch ($stylesheet->field_stylesheet_type->value()) {
    case 'custom':
      $data = $stylesheet->field_stylesheet_content->value();
      $options['type'] = 'inline';
      //$options['basename'] = $stylesheet->field_stylesheet_machine->value()['machine'];
      break;
    case 'local':
      $data = $stylesheet->field_stylesheet_path->value();
      $options['type'] = 'file';
      break;
    case 'remote':
      $data = $stylesheet->field_stylesheet_path->value();
      $options['type'] = 'external';
      break;
  }

  // Add browsers option handling

  //
  if ($group == CATALYST_MEDIA_GROUP_LAYOUT) {
    $options['every_page'] = TRUE;
  }
  drupal_add_css($data, $options);
}

function catalyst_add_js($javascript, $group = CATALYST_MEDIA_GROUP_OTHER) {
  $options = array(
    'group' => $group,
    'requires_jquery' => FALSE,
  );

  switch ($javascript->field_javascript_type->value()) {
    case 'custom':
      $data = $javascript->field_javascript_content->value();
      $options['type'] = 'inline';
      break;
    case 'local':
      $data = $javascript->field_javascript_path->value();
      $options['type'] = 'file';
      break;
    case 'remote':
      $data = $javascript->field_javascript_path->value();
      $options['type'] = 'external';
      break;
  }

  // Add scope handling

  if ($group == CATALYST_MEDIA_GROUP_LAYOUT) {
    $options['every_page'] = TRUE;
  }

  drupal_add_js($data, $options);
}


/**
 * Returns the rendered CSS for a page.
 *
 * Removes CSS not added by the catalyst system.
 *
 * @see drupal_get_css()
 * @see catalyst_html_preprocess()
 */
function catalyst_get_css() {
  $css = &drupal_static('drupal_add_css', array());
  $remove_groups = array(CSS_SYSTEM, CSS_DEFAULT, CSS_THEME);
  foreach (array_keys($css) AS $i) {
    if (in_array($css[$i]['group'], $remove_groups)) {
      unset($css[$i]);
    }
  }
  return drupal_get_css($css);
}

function catalyst_get_js($scope = 'header') {
  $javascript = &drupal_static('drupal_add_js', array());
  $remove_groups = array(JS_DEFAULT, JS_LIBRARY, JS_SETTING, JS_THEME);
  foreach (array_keys($javascript) AS $i) {
    if ($javascript[$i]['scope'] == $scope
      && in_array($javascript[$i]['group'], $remove_groups)) {
      unset($javascript[$i]);
    }
  }
  return drupal_get_js($scope, $javascript);
}
