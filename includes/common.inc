<?php

/**
 * @file
 * Common functions for Catalyst.
 */

define('CATALYST_CSS_SYSTEM', -101);
define('CATALYST_CSS_LAYOUT', 101);
define('CATALYST_CSS_PAGE', 201);
define('CATALYST_CSS_OTHER', 301);

define('CATALYST_JS_SYSTEM', -201);
define('CATALYST_JS_LIBRARY', -101);
define('CATALYST_JS_LAYOUT', 101);
define('CATALYST_JS_PAGE', 201);
define('CATALYST_JS_OTHER', 301);

/**
 * Custom delivery callback for Catalyst CMS.
 *
 * Mostly identical to the default callbac, except catalyst_render_page() is
 * called instead of drupal_render_page().
 *
 * @see catalyst_render_page()
 */
function catalyst_deliver_html_page($page_callback_result) {
  // Emit the correct charset HTTP header, but not if the page callback
  // result is NULL, since that likely indicates that it printed something
  // in which case, no further headers may be sent, and not if code running
  // for this page request has already set the content type header.
  if (isset($page_callback_result) && is_null(drupal_get_http_header('Content-Type'))) {
    drupal_add_http_header('Content-Type', 'text/html; charset=utf-8');
  }

  // Send appropriate HTTP-Header for browsers and search engines.
  global $language;
  drupal_add_http_header('Content-Language', $language->language);

 // Menu status constants are integers; page content is a string or array.
  if (is_int($page_callback_result)) {
    // @todo: Break these up into separate functions?
    switch ($page_callback_result) {
      case MENU_NOT_FOUND:
        // Print a 404 page.
        drupal_add_http_header('Status', '404 Not Found');

        watchdog('page not found', check_plain($_GET['q']), NULL, WATCHDOG_WARNING);

        // Check for and return a fast 404 page if configured.
        drupal_fast_404();

        // Keep old path for reference, and to allow forms to redirect to it.
        if (!isset($_GET['destination'])) {
          // Make sure that the current path is not interpreted as external URL.
          if (!url_is_external($_GET['q'])) {
            $_GET['destination'] = $_GET['q'];
          }
        }

        $path = drupal_get_normal_path(variable_get('site_404', ''));
        if ($path && $path != $_GET['q']) {
          // Custom 404 handler. Set the active item in case there are tabs to
          // display, or other dependencies on the path.
          menu_set_active_item($path);
          $return = menu_execute_active_handler($path, FALSE);
        }

        if (empty($return) || $return == MENU_NOT_FOUND || $return == MENU_ACCESS_DENIED) {
          // Standard 404 handler.
          drupal_set_title(t('Page not found'));
          $return = t('The requested page "@path" could not be found.', array('@path' => request_uri()));
        }

        drupal_set_page_content($return);
        $page = element_info('layout');
        print catalyst_render_page($page);
        break;

      case MENU_ACCESS_DENIED:
        // Print a 403 page.
        drupal_add_http_header('Status', '403 Forbidden');
        watchdog('access denied', check_plain($_GET['q']), NULL, WATCHDOG_WARNING);

        // Keep old path for reference, and to allow forms to redirect to it.
        if (!isset($_GET['destination'])) {
          // Make sure that the current path is not interpreted as external URL.
          if (!url_is_external($_GET['q'])) {
            $_GET['destination'] = $_GET['q'];
          }
        }

        $path = drupal_get_normal_path(variable_get('site_403', ''));
        if ($path && $path != $_GET['q']) {
          // Custom 403 handler. Set the active item in case there are tabs to
          // display or other dependencies on the path.
          menu_set_active_item($path);
          $return = menu_execute_active_handler($path, FALSE);
        }

        if (empty($return) || $return == MENU_NOT_FOUND || $return == MENU_ACCESS_DENIED) {
          // Standard 403 handler.
          drupal_set_title(t('Access denied'));
          $return = t('You are not authorized to access this page.');
        }

        print catalyst_render_page($return);
        break;

      case MENU_SITE_OFFLINE:
        // Print a 503 page.
        drupal_maintenance_theme();
        drupal_add_http_header('Status', '503 Service unavailable');
        drupal_set_title(t('Site under maintenance'));
        print theme('maintenance_page', array('content' => filter_xss_admin(variable_get('maintenance_mode_message',
        t('@site is currently under maintenance. We should be back shortly. Thank you for your patience.', array('@site' => variable_get('site_name', 'Drupal')))))));
        break;
    }
  }
  elseif (isset($page_callback_result)) {
    // Print anything besides a menu constant, assuming it's not NULL or
    // undefined.
    print catalyst_render_page($page_callback_result);
  }
  // Perform end-of-request tasks.
  drupal_page_footer();
}

/**
 * Custom page renderer for Catalyst CMS.
 *
 * @see drupal_render_page()
 */
function catalyst_render_page($page) {
  $main_content_display = &drupal_static('system_main_content_added', FALSE);

  // Allow menu callbacks to return strings or arbitrary arrays to render.
  // If the array returned is not of #type page directly, we need to fill
  // in the page with defaults.
  if (is_string($page) || (is_array($page) && (!isset($page['#type']) || ($page['#type'] != 'layout')))) {
    drupal_set_page_content($page);
    $page = element_info('layout');
  }

  // Modules can add elements to $page as needed in hook_page_build().
  foreach (module_implements('page_build') as $module) {
    $function = $module . '_page_build';
    $function($page);
  }
  // Modules alter the $page as needed. Blocks are populated into regions like
  // 'sidebar_first', 'footer', etc.
  drupal_alter('page', $page);

  // If no module has taken care of the main content, add it to the page now.
  // This allows the site to still be usable even if no modules that
  // control page regions (for example, the Block module) are enabled.
  if (!$main_content_display) {
    $page['content']['system_main'] = drupal_set_page_content();
  }

  return drupal_render($page);
}

function catalyst_add_css($stylesheet, $group = CATALYST_MEDIA_GROUP_OTHER, $delta = 0) {
  $options = array(
    'group' => $group,
    'media' => $stylesheet->field__media_stylesheet_media->value(),
    'weight' => ($delta+1) * 0.1,
  );

  $options['basename'] = $stylesheet->field__machine->machine->value();
  switch ($stylesheet->field__media_type->value()) {
    case 'custom':
      module_load_include('inc', 'catalyst', 'includes/twig');
      $template = new CatalystStylesheetTemplate($stylesheet->value());
      $data = $template->renderTemplate();
      $options['type'] = 'inline';
      break;
    case 'local':
      $data = $stylesheet->field__media_path->value();
      $options['type'] = 'file';
      break;
    case 'remote':
      $data = $stylesheet->field__media_path->value();
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

function catalyst_add_custom_css($data, $group, $field, $entity_id) {
  $custom_css = &drupal_static(__FUNCTION__, array());

  $key = $field . ':' . $entity_id;
  if (!isset($custom_css[$key])) {
    catalyst_include('twig');
    drupal_add_css(catalyst_twig_render($data, array(), $key), array(
      'type' => 'inline',
      'media' => 'all',
      'group' => $group,
    ));
    $custom_css[$key] = 1;
  }
}
function catalyst_add_custom_js($data, $group, $field, $entity_id) {
  $custom_js = &drupal_static(__FUNCTION__, array());

  $key = $field . ':' . $entity_id;
  if (!isset($custom_js[$key])) {
    drupal_add_js($data, array(
      'type' => 'inline',
      'scope' => 'header',
      'group' => $group,
      'weight' => 1,
    ));
    $custom_js[$key] = 1;
  }
}

function catalyst_add_js($javascript, $group = CATALYST_MEDIA_GROUP_OTHER) {
  $options = array(
    'group' => $group,
    'requires_jquery' => FALSE,
    'scope' => $javascript->field__media_javascript_scope->value(),
    'defer' => $javascript->field__media_javascript_defer->value(),
  );

  switch ($javascript->field__media_type->value()) {
    case 'custom':
      $data = $javascript->field__body->value->value();
      $options['type'] = 'inline';
      break;
    case 'local':
      $data = $javascript->field__media_path->value();
      $options['type'] = 'file';
      break;
    case 'remote':
      $data = $javascript->field__media_path->value();
      $options['type'] = 'external';
      break;
  }

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
  $layout = catalyst_get_layout();
  $remove_groups = array_diff($remove_groups, $layout->getDrupalCSSOptions());

  foreach (array_keys($css) AS $i) {
    if (in_array($css[$i]['group'], $remove_groups)) {
      unset($css[$i]);
    }
  }
  return drupal_get_css($css);
}

function catalyst_get_js($scope = 'header') {
  $javascript = &drupal_static('drupal_add_js', array());
  $remove_groups = array(JS_DEFAULT, JS_LIBRARY, JS_THEME);
  $layout = catalyst_get_layout();
  $remove_groups = array_diff($remove_groups, $layout->getDrupalJSOptions());

  foreach (array_keys($javascript) AS $i) {
    if ($i == 'settings') continue;
    if ($javascript[$i]['scope'] == $scope
      && in_array($javascript[$i]['group'], $remove_groups)) {
      unset($javascript[$i]);
    }
  }
  return drupal_get_js($scope, $javascript);
}

function catalyst_load_blocks() {
  $block_info = module_invoke_all('block_placements');
  drupal_alter('block_placements', $block_info);

  $blocks = array();
  foreach ($block_info AS $placement) {
    $placement = (object)$placement;
    if ($block = entity_load_single('catalyst', $placement->block_id)) {
      $machine = $block->field__machine[$block->language][0]['machine'];
      $blocks[$placement->region][$machine] = array(
        'content' => entity_view('catalyst', array($block)),
        '#weight' => $placement->weight,
      );
    }
  }
  return $blocks;
}

/**
 *
 */
function catalyst_blocks_by_region($region) {
  $blocks = &drupal_static(__FUNCTION__);

  if (!isset($blocks)) {
    $blocks = catalyst_load_blocks();
  }

  if (!isset($blocks[$region])) {
    $blocks[$region] = array();
  }

  return $blocks[$region];
}

/**
 *
 * @param $code string
 *   A string of php code without opening and closing tags.
 *
 * @param $variables array
 *   An array of variables that the $code is able to modify. $variables are
 *   intended for a template.
 * @return NULL or boolean
 *   Evaluations with catalyst_eval() must return null or boolean. Code
 *   processed by catalyst_eval() should never return a string. An exception
 *   will be thrown anticipating a syntax error when a string is returned.
 * @param array $___exportvars
 *   Array of "non-$variables" variables that the code cannot modify. Export
 *   vars are accessible at the top-level of evaluations, but are not
 *   passed on to templates (but can be manually in preprocessing).
 *
 * @todo Improve exception error message/handling for better debugging.
 */
function catalyst_eval($code, &$variables, $___exportvars = array()) {
  extract($___exportvars);
  unset($___exportvars);
  ob_start();
  $result = eval($code);
  $output = ob_get_contents();
  ob_end_clean();
  if (!in_array($result, array(NULL, TRUE, FALSE, 0, 1))) {
    throw new Exception($output);
  }
  return $result;
}

/**
 * Workaround for this issue with entity_metadata_wrapper:
 * https://www.drupal.org/node/1596594
 */
function entity_valval(EntityStructureWrapper $data) {
  if ($data->value()) {
    return $data->value->value();
  }
}
