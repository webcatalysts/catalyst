<?php

/**
 * @file
 *
 * Base template wrapper for Catalyst.
 */

/**
 * This class is mainly for convenience but the template wrapper's main
 * job is to provide base functionality when the corresponding template
 * does not exist.
 */
interface CatalystTemplateInterface {
  public function renderTemplate($variables);
  public function getHTMLHead();
  public function getPreprocessPHP();
}

interface CatalystLayoutInterface extends CatalystTemplateInterface {
  public function getLayoutID();
  public function getDoctype();
  public function getRegions();
  public function getDebuggingEnabled();
  public function getShowMessages();
  public function getPageTitlePattern();
  public function getBlockPlacements();
  public function getDrupalProcessingEnabled();
}

interface CatalystDoctypeInterface extends CatalystTemplateInterface {
  public function getContentType();
  public function getCharset();
  public function getDrupalProcessingEnabled();
}

abstract class CatalystEntityTemplate implements CatalystTemplateInterface {
  abstract protected function getDefaultTemplate();

  const ENTITY_TYPE = 'catalyst';
  protected $has_entity = FALSE;
  protected $wrapper;
  protected $template;

  public function __construct($entity = FALSE) {
    if ($entity != FALSE) {
      $this->setEntity(self::ENTITY_TYPE, $entity);
    }
  }

  protected function setEntity($entity_type, $entity) {
    $this->has_entity = TRUE;
    $this->wrapper = entity_metadata_wrapper($entity_type, $entity);
    $this->template = $this->retrieveTemplate();
  }

  protected function getTemplate() {
    if ($this->has_entity) {
      return $this->template;
    }
    return $this->getDefaultTemplate();
  }

  protected function retrieveTemplate() {
    $build = eck__entity__view(
      $this->wrapper->type(),
      $this->wrapper->getBundle(),
      $this->wrapper->value()
    );
    return render($build);
  }

  public function getDrupalProcessingEnabled() {
    if ($this->has_entity) {
      return $this->wrapper->field__drupal_processing->value();
    }
    return FALSE;
  }

  protected function getTemplateName() {
    if ($this->has_entity) {
      return format_string('@entity_type:@entity_bundle:@entity_id', array(
        '@entity_type' => $this->wrapper->type(),
        '@entity_bundle' => $this->wrapper->getBundle(),
        '@entity_id' => $this->wrapper->getIdentifier(),
      ));
    }
    return get_class($this);
  }
}

abstract class CatalystNodeTemplate implements CatalystTemplateInterface {
  protected $wrapper;

  public function __construct($node) {
    $this->wrapper = entity_metadata_wrapper('node', $node);
  }

  abstract function getTemplate();

  protected function getTemplateName() {
    return format_string('@node_type:@node_id', array(
      '@node_type' => $this->wrapper->getBundle(),
      '@node_id' => $this->wrapper->getIdentifier(),
    ));
    return get_class($this);
  }
}

trait CatalystTwigTemplateRenderer {
  public function renderTemplate($variables) {
    module_load_include('inc', 'catalyst', 'includes/twig');

    $render_wrapper = &drupal_static('twig_render_entity_wrapper', NULL);
    $render_wrapper = $this->wrapper;

    $return = catalyst_twig_render(
      $this->getTemplate(),
      $variables,
      $this->getTemplateName()
    );

    drupal_static_reset('twig_render_entity_wrapper');

    return $return;
  }
}

trait CatalystLayoutDefaultTwigTemplate {
  use CatalystTwigTemplateRenderer;
  protected function getDefaultTemplate() {
    return "{{ content }}";
  }
}

trait CatalystDoctypeDefaultTwigTemplate {
  use CatalystTwigTemplateRenderer;
  protected function getDefaultTemplate() {
    return field__body_default_value();
  }
}
