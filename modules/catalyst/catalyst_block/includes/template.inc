<?php

/**
 * @file
 */

class CatalystBlockTemplate extends CatalystEntityTemplate {
  use CatalystTwigTemplateRenderer;

  protected function getDefaultTemplate() {
    return NULL;
  }
  protected function retrieveTemplate() {
    return $this->wrapper->field_block_content->value->value();
  }

  public function getHTMLHead() {
    return NULL;
  }
  public function getPreprocessPHP() {
    return entity_valval($this->wrapper->field_block_preprocess);
  }
}

