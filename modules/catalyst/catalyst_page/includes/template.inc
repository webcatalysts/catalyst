<?php

/**
 * @file
 */

class CatalystNodePage extends CatalystNodeTemplate {
  use CatalystTwigTemplateRenderer;

  const ENTITY_TYPE = 'node';
  public function getTemplate() {
    return entity_valval($this->wrapper->field_cpage_content);
  }
  public function getHTMLHead() {
    return entity_valval($this->wrapper->field_cpage_head);
  }
  public function getDefaultTemplate() {
    return "";
  }
  public function getPreprocessPHP() {
    return entity_valval($this->wrapper->field_cpage_preprocess);
  }
}
