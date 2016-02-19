<?php

/**
 * @file
 */

class CatalystStylesheetTemplate extends CatalystEntityTemplate {
  use CatalystTwigTemplateRenderer;

  // Need to adjust the base classes as these methods are irrelevant here
  protected function getDefaultTemplate() { return NULL; }
  public function getHTMLHead() { return NULL; }
  public function getPreprocessPHP() { return NULL; }

  public function retrieveTemplate() {
    return $this->wrapper->field__body->value->value();
  }
}
