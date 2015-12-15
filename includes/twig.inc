<?php

/**
 *
 */

function catalyst_twig_render($template, $variables = array(), $key = NULL) {
  require_once DRUPAL_ROOT . '/profiles/catalyst/libraries/twig/lib/Twig/Autoloader.php';
  Twig_Autoloader::register();
  if (empty($key)) {
    $key = 'index.html';
  }
  $loader = new Twig_Loader_Array(array($key => $template));
  $twig = new Twig_Environment($loader, array(
    'debug' => TRUE,
    'autoescape' => FALSE,
  ));

  $twig->addFunction(new Twig_SimpleFunction('t', 't'));
  $twig->addFilter(new Twig_SimpleFilter('t', 't'));
  $twig->addFunction(new Twig_SimpleFunction('render', 'render'));
  $twig->addFilter(new Twig_SimpleFilter('render', 'render'));
  drupal_alter(__FUNCTION__, $twig, $variables, $key);

  return $twig->render($key, $variables);
}
