<?php
/**
 * @file
 * csv.inc
 */


abstract class BetterMigrationCSV extends BetterMigrationBase {
  /**
   * Optional - keys are field names, values are descriptions. Use to override
   * the default descriptions, or to add additional source fields which the
   * migration will add via other means (e.g., prepareRow()).
   *
   * @var array
   * @see MigrateSourceCSV::__construct()
   */
  protected $fields = array();
  public function getFields() {
    if (empty($this->fields)) {
      $this->fields = $this->fields();
    }
    return $this->fields;
  }
  protected function fields() {
    return array('module');
  }

  /**
   * @var string
   */
  protected $csvFilename;

  /**
   * @var int
   */
  protected $headerRows = 1;

  /**
   * Abstract method, extending classes must define the CSV columns using
   * this method.
   *
   * @return Array
   *   An array describing the CSV columns
   */
  abstract protected function columns();

  protected function options() {
    return array('header_rows' => $this->headerRows, 'embedded_newlines' => TRUE);
  }

  protected function initSource() {
    return new MigrateSourceCSV($this->dataDirectory() . '/' . $this->csvFilename, $this->columns(), $this->options(), $this->fields());
  }

  protected function csvFilename() {
    return empty($this->csvFilename) ? get_class($this) . '.csv' : $this->csvFilename;
  }

  protected function initMapSimple(Array $map) {
    $schema = call_user_func(get_class($this->destination) . '::getKeySchema');
    return new MigrateSQLMap($this->machineName, $map, $schema);
  }
  protected function initMapSimpleID($key = 'id') {
    return $this->initMapSimple(array(
      $key => array(
        'type' => 'int',
        'unsigned' => TRUE,
        'not null' => TRUE,
      ),
    ));
  }
}
