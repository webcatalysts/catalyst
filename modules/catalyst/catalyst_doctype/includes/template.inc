<?php

/**
 * @file
 */

class CatalystEntityDoctype extends CatalystEntityTemplate implements CatalystDoctypeInterface {
  use CatalystDoctypeDefaultTwigTemplate;

  public function getHTMLHead() {
    return NULL;
  }

  public function getContentType() {
    if ($this->has_entity) {
      return $this->wrapper->field_doctype_content_type->value();
    }
    return 'text/html';
  }

  public function getCharset() {
    if ($this->has_entity) {
      return $this->wrapper->field_doctype_charset->value();
    }
    return 'utf-8';
  }

  public function getPreprocessPHP() {
    if ($this->has_entity) {
      return entity_valval($this->wrapper->field_doctype_preprocess);
    }
  }
}
