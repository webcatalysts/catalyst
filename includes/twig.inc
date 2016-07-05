<?php

/**
 *
 */

function catalyst_twig_render($template, $variables = array(), $key = NULL) {
  $path = libraries_get_path('twig');
  require_once DRUPAL_ROOT . '/' . $path . '/lib/Twig/Autoloader.php';
  Twig_Autoloader::register();
  if (empty($key)) {
    $key = 'index.html';
  }
  $loader = new Twig_Loader_Array(array($key => $template));
  $twig = new Twig_Environment($loader, array(
    'debug' => TRUE,
    'autoescape' => FALSE,
  ));

  $extensions = array(
    'addFunction' => array(
      't' => new Twig_SimpleFunction('t', 't'),
      'render' => new Twig_SimpleFunction('render', 'catalyst_render'),
    ),
    'addFilter' => array(
      't' => new Twig_SimpleFilter('t', 't'),
      'render' => new Twig_SimpleFilter('render', 'catalyst_render'),
    ),
  );
  /*
  $twig->addFunction(new Twig_SimpleFunction('t', 't'));
  $twig->addFilter(new Twig_SimpleFilter('t', 't'));
  $twig->addFunction(new Twig_SimpleFunction('render', 'render'));
  $twig->addFilter(new Twig_SimpleFilter('render', 'render'));
  // */
  //
  drupal_alter(__FUNCTION__, $twig, $extensions, $variables, $key);

  foreach ($extensions AS $callback => $items) {
    foreach ($items AS $extension) {
      $twig->{$callback}($extension);
    }
  }
  return $twig->render($key, $variables);
}

function catalyst_render($var) {
  return render($var);
}

