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
  public function getDrupalProcessingEnabled();
  public function getPreprocessPHP();
}

interface CatalystLayoutInterface extends CatalystTemplateInterface {
  public function getDoctype();
  public function getRegions();
  public function getDebuggingEnabled();
  public function getShowMessages();
  public function getPageTitlePattern();
}

interface CatalystDoctypeInterface extends CatalystTemplateInterface {
  public function getContentType();
  public function getCharset();
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
    if (!empty($this->template)) {
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
      return $this->wrapper->field_catalyst_drupal_processing->value();
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

trait CatalystTwigTemplateRenderer {
  public function renderTemplate($variables) {
    module_load_include('inc', 'catalyst', 'includes/twig');

    return catalyst_twig_render(
      $this->getTemplate(),
      $variables,
      $this->getTemplateName()
    );
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
    return field_doctype_content_default_value();
  }
}
