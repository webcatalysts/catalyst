<?php

/**
 * @file
 */

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
  public function getTemplate() {
    return entity_valval($this->wrapper->field__body);
  }
}
