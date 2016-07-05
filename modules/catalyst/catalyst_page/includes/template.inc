<?php

/**
 * @file
 */

class CatalystNodePage extends CatalystNodeTemplate {
  use CatalystTwigTemplateRenderer;

  const ENTITY_TYPE = 'node';
  public function getTemplate() {
    return entity_valval($this->wrapper->field__body);
  }
  public function getHTMLHead() {
    return entity_valval($this->wrapper->field__html_head);
  }
  public function getDefaultTemplate() {
    return "";
  }
  public function getPreprocessPHP() {
    return entity_valval($this->wrapper->field__preprocess);
  }
  public function getMenuPath() {
    if (isset($this->wrapper->field__menu)) {
      $value = entity_valval($this->wrapper->field__menu);
      return $value['path'];
    }
  }
}

class CatalystEntityPage extends CatalystEntityTemplate {
  use CatalystTwigTemplateRenderer;

  public function getHTMLHead() {
    return entity_valval($this->wrapper->field__html_head);
  }

  public function getDefaultTemplate() {
    return "";
  }
  public function getPreprocessPHP() {
    return entity_valval($this->wrapper->field__preprocess);
  }
  public function getMenuPath() {
    $value = entity_valval($this->wrapper->field__menu);
    return $value['path'];
  }
}
