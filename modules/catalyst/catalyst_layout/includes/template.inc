<?php

/**
 * @file
 */
class CatalystEntityLayout extends CatalystEntityTemplate implements CatalystLayoutInterface {
  use CatalystLayoutDefaultTwigTemplate;

  public function getDoctype() {
    $doctype = FALSE;
    if ($this->has_entity) {
      $doctype = $this->wrapper->field_layout_doctype->value();
    }
    return new CatalystEntityDoctype($doctype);
  }

  public function getRegions() {
    $regions = array();
    if ($this->has_entity) {
      foreach ($this->wrapper->field_layout_regions->value() AS $region) {
        $regions[] = $region;
      }
    }
    return $regions;
  }

  public function getHTMLHead() {
    if ($this->has_entity) {
      return entity_valval($this->wrapper->field_layout_html_head);
    }
    return NULL;
  }

  public function getPreprocessPHP() {
    if ($this->has_entity) {
      return entity_valval($this->wrapper->field_layout_preprocess);
    }
    return NULL;
  }

  public function getDebuggingEnabled() {
    if ($this->has_entity) {
      return $this->wrapper->field_layout_debug->value();
    }
    return FALSE;
  }

  public function getShowMessages() {
    if ($this->has_entity) {
      return $this->wrapper->field_layout_show_messages->value();
    }
    return FALSE;
  }

  public function getPageTitlePattern() {
    if ($this->has_entity) {
      return $this->wrapper->field_layout_page_title_pattern->value();
    }
    return '{{ title }}';
  }
}
