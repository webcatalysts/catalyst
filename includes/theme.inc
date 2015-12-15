<?php


function theme_layout($variables) {
  require_once DRUPAL_ROOT . '/profiles/catalyst/includes/twig.inc';
  global $catalyst_layout;
  //catalyst_layout_initialize();
  $template = $catalyst_layout->field_layout_content->value();
  $template = $template['value'];
  dsm($variables);
  return catalyst_twig_render($template, $variables);
}

/*
function theme_doctype($variables) {
  global $catalyst_layout;
  $prefix = $suffix = '';
  $doctype = $catalyst_layout->field_layout_doctype;
  if ($header = $doctype->field_doctype_header->value()) {
    $prefix = catalyst_twig_render($header, $variables);
  }
  if ($footer = $doctype->field_doctype_footer->value()) {
    $suffix = catalyst_twig_render($footer, $variables);
  }
  return implode("\n", array($prefix, $variables['doctype']['#children'], $suffix));
}
 */

/*
function template_process_doctype(&$variables) {
  global $catalyst_layout;
  $doctype = $catalyst_layout->field_layout_doctype;
  if ($preprocess_php = $doctype->field_doctype_preprocess->value()) {
    eval($preprocess_php);
  }
  template_process($variables);
}
 */

function template_process_layout(&$variables) {
  //template_process_page($variables);

  foreach (element_children($variables['layout']) AS $i) {
    $variables[$i] = render($variables['layout'][$i]);
  }
}

function catalyst_preprocess_layout(&$variables) {
  $variables['title'] = drupal_get_title();

  // Compile a list of classes that are going to be applied to the body element.
  // This allows advanced theming based on context (home page, node of certain type, etc.).
  // Add a class that tells us whether we're on the front page or not.
  $variables['classes_array'][] = $variables['is_front'] ? 'front' : 'not-front';
  // Add a class that tells us whether the page is viewed by an authenticated user or not.
  $variables['classes_array'][] = $variables['logged_in'] ? 'logged-in' : 'not-logged-in';

  global $catalyst_layout;
  $template = eck__entity__view('catalyst', 'layout', $catalyst_layout->value());
  if ($preprocess_php = $catalyst_layout->field_layout_preprocess->value()['value']) {
    eval($preprocess_php);
  }
}

function catalyst_process_layout(&$variables) {
  // Render page_top and page_bottom into top level variables.
  $variables['page_top'] = drupal_render($variables['page']['page_top']);
  $variables['page_bottom'] = drupal_render($variables['page']['page_bottom']);
  // Place the rendered HTML for the page body into a top level variable.
  $variables['page'] = $variables['page']['#children'];
  $variables['page_bottom'] .= drupal_get_js('footer');

  $variables['head'] = drupal_get_html_head();
  $variables['styles'] = catalyst_get_css();
  $variables['scripts'] = catalyst_get_js();
  $variables['closure'] = catalyst_get_js('footer');

//  module_invoke_all('catalyst_html_preprocess', $variables);
}
