<?php
/**
 * @file
 * xml.inc
 */

trait BetterMigrationSourceXML {

  protected function getXmlFilename() {
    if (!empty($this->arguments['xml_filename'])) {
      $this->xmlFilename = $this->arguments['xml_filename'];
    }
    elseif (empty($this->xmlFilename)) {
      $this->xmlFilename = strtolower(get_class($this)) . '.xml';
    }
    return $this->xmlFilename;
  }

  protected function getItemXpath() {
    if (!empty($this->arguments['item_xpath'])) {
      $this->itemXpath = $this->arguments['item_xpath'];
    }
    if (!empty($this->itemXpath)) {
      return $this->itemXpath;
    }
    // trigger error
  }

  protected function getItemXpathID() {
    if (!empty($this->arguments['item_xpath_id'])) {
      $this->itemXpathID = $this->arguments['item_xpath_id'];
    }
    if (!empty($this->itemXpathID)) {
      return $this->itemXpathID;
    }
    // trigger error
  }

  /**
   * Abstract method, classes using this trait must define the XML fields using
   * this method.
   *
   * @return Array
   *   An array describing the XML fields
   */
  abstract protected function sourceFields();

  protected function getFields() {
    // Allow fields to be overridden with arguments
    if (!empty($this->arguments['source_fields'])) {
      return $this->arguments['source_fields'];
    }
    return $this->sourceFields();
  }

  protected function initSource() {
    return new MigrateSourceXML(
      $this->getDataDirectory() . '/' . $this->getXmlFilename(),
      $this->getItemXpath(),
      $this->getItemXpathID(),
      $this->getFields(),
      $this->getSourceOptions()
    );
  }

  /**
   * {@inheritdoc}
   *
   * So we can create our special field mapping class.
   *
   * @todo Find a cleaner way to just substitute a different mapping class.
   *
   * @param string|null $destination_field
   *   machine-name of destination field
   * @param string|null $source_field
   *   name of source field
   * @param bool $warn_on_override
   *   Set to FALSE to prevent warnings when there's an existing mapping
   *   for this destination field.
   *
   * @return MigrateXMLFieldMapping
   *   MigrateXMLFieldMapping
   */
  public function addFieldMapping($destination_field, $source_field = NULL,
                                  $warn_on_override = TRUE) {
    // Warn of duplicate mappings.
    if ($warn_on_override && !is_null($destination_field) && isset($this->codedFieldMappings[$destination_field])) {
      self::displayMessage(
        t('!name addFieldMapping: !dest was previously mapped, overridden',
          array('!name' => $this->machineName, '!dest' => $destination_field)),
        'warning');
    }
    $mapping = new MigrateXMLFieldMapping($destination_field, $source_field);
    if (is_null($destination_field)) {
      $this->codedFieldMappings[] = $mapping;
    }
    else {
      $this->codedFieldMappings[$destination_field] = $mapping;
    }
    $mapping->xpath($source_field);
    return $mapping;
  }

  /**
   * {@inheritdoc}
   *
   * A normal $data_row has all the input data as top-level fields - in this
   * case, however, the data is embedded within a SimpleXMLElement object in
   * $data_row->xml. Explode that out to the normal form, and pass on to the
   * normal implementation.
   */
  protected function applyMappings() {
    // We only know what data to pull from the xpaths in the mappings.
    foreach ($this->getFieldMappings() as $mapping) {
      $source = $mapping->getSourceField();
      if ($source && !isset($this->sourceValues->{$source})) {
        if (!$xpath = $mapping->getXpath()) {
          $xpath = $source;
        }
        if ($xpath) {
          // Derived class may override applyXpath().
          $source_value = $this->applyXpath($this->sourceValues, $xpath);
          if (!is_null($source_value)) {
            $this->sourceValues->$source = $source_value;
          }
        }
      }
    }
    parent::applyMappings();
  }

  /**
   * Gets item from XML using the xpath.
   *
   * Default implementation - straightforward xpath application
   *
   * @param stdClass $data_row
   *   row containing items.
   * @param string $xpath
   *   xpath used to find the item
   *
   * @return SimpleXMLElement
   *   found element
   */
  public function applyXpath($data_row, $xpath) {
    $result = $data_row->xml->xpath($xpath);
    if ($result) {
      if (count($result) > 1) {
        $return = array();
        foreach ($result as $record) {
          $return[] = (string) $record;
        }
        return $return;
      }
      else {
        return (string) $result[0];
      }
    }
    else {
      return NULL;
    }
  }
}
