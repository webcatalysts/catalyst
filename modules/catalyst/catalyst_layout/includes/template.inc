<?php

/**
 * @file
 */
class CatalystEntityLayout extends CatalystEntityTemplate implements CatalystLayoutInterface {
  use CatalystLayoutDefaultTwigTemplate;

  public function getLayoutID() {
    if ($this->has_entity) {
      return $this->wrapper->getIdentifier();
    }
    return FALSE;
  }

  public function getDoctype() {
    $doctype = FALSE;
    if ($this->has_entity) {
      $doctype = $this->wrapper->field__doctype->value();
    }
    return new CatalystEntityDoctype($doctype);
  }

  public function getRegions() {
    $regions = array();
    if ($this->has_entity) {
      foreach ($this->wrapper->field__layout_regions->value() AS $region) {
        $regions[] = $region['machine'];
      }
    }
    return $regions;
  }

  public function getHTMLHead() {
    if ($this->has_entity) {
      return entity_valval($this->wrapper->field__html_head);
    }
    return NULL;
  }

  public function getPreprocessPHP() {
    if ($this->has_entity) {
      return entity_valval($this->wrapper->field__preprocess);
    }
    return NULL;
  }

  public function getDebuggingEnabled() {
    if ($this->has_entity) {
      return $this->wrapper->field__debug->value();
    }
    return FALSE;
  }

  public function getShowMessages() {
    if ($this->has_entity) {
      return $this->wrapper->field__layout_show_messages->value();
    }
    return FALSE;
  }

  public function getPageTitlePattern() {
    if ($this->has_entity) {
      return $this->wrapper->field__layout_page_title_pattern->value();
    }
    return '{{ title }}';
  }

  public function getBlockPlacements() {
    if ($this->has_entity) {
      return $this->wrapper->field__blockplacements__layout->value();
    }
    return array();
  }
}
