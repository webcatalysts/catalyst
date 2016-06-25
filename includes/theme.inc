<?php


function theme_doctype($variables) {
  $doctype = $variables['page']['#doctype'];
  $variables['page'] = $variables['page']['#children'];
  return $doctype->renderTemplate($variables);
}

function theme_layout($variables) {
  return $variables['page']['#layout']->renderTemplate($variables);
}

function template_preprocess_doctype(&$variables) {
  $doctype = $variables['page']['#doctype'];

  // Construct page title.
  if (drupal_get_title()) {
    $head_title = array(
      'title' => strip_tags(drupal_get_title()),
      'name' => check_plain(variable_get('site_name', 'Drupal')),
    );
  }
  else {
    $head_title = array('name' => check_plain(variable_get('site_name', 'Drupal')));
    if (variable_get('site_slogan', '')) {
      $head_title['slogan'] = filter_xss_admin(variable_get('site_slogan', ''));
    }
  }
  $variables['head_title_array'] = $head_title;
  $variables['head_title'] = implode(' | ', $head_title);

  if($variables['drupal_processing'] = $doctype->getDrupalProcessingEnabled()) {
    drupal_preprocess_doctype($variables);
  }
}

function drupal_preprocess_doctype(&$variables) {
  // Not sure why this isn't being called automatically
  template_preprocess($variables, 'doctype');

  // Compile a list of classes that are going to be applied to the body element.
  // This allows advanced theming based on context (home page, node of certain type, etc.).
  // Add a class that tells us whether we're on the front page or not.
  $variables['classes_array'][] = $variables['is_front'] ? 'front' : 'not-front';
  // Add a class that tells us whether the page is viewed by an authenticated user or not.
  $variables['classes_array'][] = $variables['logged_in'] ? 'logged-in' : 'not-logged-in';

  // Add information about the number of sidebars.
  if (!empty($variables['page']['region']['sidebar_first']) && !empty($variables['region']['sidebar_second'])) {
    $variables['classes_array'][] = 'two-sidebars';
  }
  elseif (!empty($variables['page']['region']['sidebar_first'])) {
    $variables['classes_array'][] = 'one-sidebar sidebar-first';
  }
  elseif (!empty($variables['page']['region']['sidebar_second'])) {
    $variables['classes_array'][] = 'one-sidebar sidebar-second';
  }
  else {
    $variables['classes_array'][] = 'no-sidebars';
  }

  // If on an individual node page, add the node type to body classes.
  if ($node = menu_get_object()) {
    $variables['classes_array'][] = drupal_html_class('node-type-' . $node->type);
  }

  // RDFa allows annotation of XHTML pages with RDF data, while GRDDL provides
  // mechanisms for extraction of this RDF content via XSLT transformation
  // using an associated GRDDL profile.
  $variables['rdf_namespaces']    = drupal_get_rdf_namespaces();
  $variables['grddl_profile']     = 'http://www.w3.org/1999/xhtml/vocab';
  $variables['language']          = $GLOBALS['language'];
  $variables['language']->dir     = $GLOBALS['language']->direction ? 'rtl' : 'ltr';

}

function template_process_doctype(&$variables) {
  if ($variables['drupal_processing']) {
    drupal_process_doctype($variables);
  }

  // Render page_top and page_bottom into top level variables.
  $variables['page_top'] = drupal_render($variables['page']['page_top']);
  $variables['page_bottom'] = drupal_render($variables['page']['page_bottom']);
  $variables['page_bottom'] .= catalyst_get_js('footer');
  $variables['content'] = drupal_render($variables['page']['content']);

  $variables['head'] = drupal_get_html_head();
  $variables['styles'] = catalyst_get_css();
  $variables['scripts'] = catalyst_get_js();
}

function drupal_process_doctype(&$variables) {
  template_process($variables, 'doctype');
}

/**
 * Initial preprocessing for layouts.
 *
 * @see template_preprocess_html()
 * @see template_preprocess_page()
 */
function template_preprocess_layout(&$variables) {
  $layout = $variables['page']['#layout'];

  $variables['drupal_processing'] = $layout->getDrupalProcessingEnabled();
  $variables['debug'] = $layout->getDebuggingEnabled();
  $variables['show_messages'] = $layout->getShowMessages();

  $variables['title'] = drupal_get_title();

  foreach ($layout->getRegions() AS $region) {
    $variables['region'][$region] = catalyst_blocks_by_region($region);
  }

  if ($variables['drupal_processing']) {
    drupal_preprocess_layout($variables);
  }
}

function drupal_preprocess_layout(&$variables) {
  // Not sure why this isn't being called automatically
  template_preprocess($variables, 'layout');

  // Set up layout variable.
  $variables['page_layout'] = 'none';
  if (!empty($variables['region']['sidebar_first'])) {
    $variables['page_layout'] = 'first';
  }
  if (!empty($variables['region']['sidebar_second'])) {
    $variables['page_layout'] = ($variables['page_layout'] == 'first') ? 'both' : 'second';
  }

  $variables['base_path']         = base_path();
  $variables['front_page']        = url();
  $variables['feed_icons']        = drupal_get_feeds();
  $variables['language']          = $GLOBALS['language'];
  $variables['language']->dir     = $GLOBALS['language']->direction ? 'rtl' : 'ltr';
  $variables['logo']              = theme_get_setting('logo');
  $variables['main_menu']         = theme_get_setting('toggle_main_menu') ? menu_main_menu() : array();
  $variables['secondary_menu']    = theme_get_setting('toggle_secondary_menu') ? menu_secondary_menu() : array();
  $variables['action_links']      = menu_local_actions();
  $variables['site_name']         = (theme_get_setting('toggle_name') ? filter_xss_admin(variable_get('site_name', 'Drupal')) : '');
  $variables['site_slogan']       = (theme_get_setting('toggle_slogan') ? filter_xss_admin(variable_get('site_slogan', '')) : '');
  $variables['tabs']              = menu_local_tabs();

  if ($node = menu_get_object()) {
    $variables['node'] = $node;
  }
}

function template_process_layout(&$variables) {
  // Render the regions
  if (isset($variables['region'])) {
    foreach (array_keys($variables['region']) AS $region) {
      $variables['region'][$region] = render($variables['region'][$region]);
    }
  }

  $variables['content'] = drupal_render($variables['page']['content']);

  if ($variables['drupal_processing']) {
    drupal_process_layout($variables);
  }
}

function drupal_process_layout(&$variables) {
  $variables['actions_links'] = drupal_render($variables['action_links']);
  $variables['tabs'] = drupal_render($variables['tabs']);

  template_process($variables, 'layout');

  $variables['messages'] = $variables['show_messages'] ? theme('status_messages') : '';
}
