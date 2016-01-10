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

  protected function preRender(&$template, &$variables) {
    if ($this->has_entity) {
      $variables['entity'] = catalyst_entity_normalize($this->wrapper->value(), 'layout');
    }
  }

  protected function postRender(&$template, $variables) {
    if ($this->getDebuggingEnabled()) {
      $nodebug_vars = array('theme_hook_original', 'theme_hook_suggestions', 'page');
      foreach ($nodebug_vars AS $var) {
        if (isset($variables[$var])) {
          unset($variables[$var]);
        }
      }
      if ($debug = kpr($variables, !$variables['show_messages'])) {
        // This is kludgy. If dpm, kpr, etc is called after this, devel css and js
        // doesn't get included
        $devel_path = drupal_get_path('module', 'devel');
        drupal_add_css($devel_path . '/devel.css?x1', array('group' => -201));
        drupal_add_js($devel_path . '/devel_krumo_path.js?x1', array('group' => -201));
        $template .= '<h3>Debugging for: ' . $this->getTemplateName() . '</h3>' . "\n";
        $template .= '<div id="template-debug">' . $debug . '</div>' . "\n";
      }
    }
  }
}
