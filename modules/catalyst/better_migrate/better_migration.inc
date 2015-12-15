<?php
/**
 * @file
 * base.inc
 */

abstract class BetterMigration extends Migration {
  protected function getDataDirectory() {
    if (!empty($this->arguments['data_directory'])) {
      return $this->arguments['data_directory'];
    }
    if (empty($this->dataDirectory)) {
      $obj = new ReflectionClass($this);
      $this->dataDirectory = dirname($obj->getFileName());
    }
    return $this->dataDirectory;
  }

  /**
   * Define our migration group using a constant so that it can be change in
   * inheriting classes without defining a constructor method.
   *
   * Default to our testing group.
   *
   * @see BetterMigration::__construct()
   * @var string
   */
  //const GROUP = MIGRATION_GROUP_TESTING;

  abstract protected function initMap();
  abstract protected function initDestination();
  abstract protected function initSource();
  abstract protected function mapFields();

  /**
   * The intent of this class structure is so that you don't have to override
   * the constructor in your base classes. If you do run into a situation where
   * you need to override this, it is suggested that you continue to use the
   * initialization methods.
   */
  public function __construct($arguments = array()) {
    // Call the parent constructor to get initialized
    parent::__construct($arguments);

    // Translate our description if not empty, this allows us to define
    // our $description attribute as a class attribute instead of in the
    // constructor
    if (!empty($this->description)) {
      $this->description = t($this->description);
    }

    // Initialize our source, destination, and map using methods so that
    // the relevant logic can be easily overridden without having to override
    // the entire constructor
    $this->source      = $this->initSource();
    $this->destination = $this->initDestination();
    $this->map         = $this->initMap();

    // Invoke our field mapping method
    $this->mapFields();
  }

  /**
   * Migrations can be dynamic or not. Migrations derriving from
   * DynamicMigration are not automatically registered. Typically, you would
   * extend the DynamicMigration class, but since we are extending it here,
   * changing this constant to evaluate false should allow your subclass that
   * extends BetterMigration (and DynamicMigration) to be autoregistered.
   *
   * @todo Needs tested, I don't think self works here.
   * @see DynamicMigratoin::isDynamic()
   * @var bool
   */
  const DYNAMIC = TRUE;
  static public function isDynamic() {
    return self::DYNAMIC;
  }


  protected function getSourceOptions() {
    if (!empty($this->arguments['source_options'])) {
      $this->sourceOptions = $this->arguments['source_options'];
    }
    if (empty($this->sourceOptions)) {
      $this->sourceOptions = array();
    }
    return $this->sourceOptions;
  }

  protected function getDestinationOptions() {
    if (!empty($this->arguments['destination_options'])) {
      $this->destinationOptions = $this->arguments['destination_options'];
    }
    if (empty($this->destinationOptions)) {
      $this->destinationOptions = array();
    }
    return $this->destinationOptions;
  }

  /**
   * Destination traits should override this method when necessary.
   */
  /*
  protected function getMapSchema() {
    return call_user_func(get_class($this->destination) . '::getKeySchema');
  }
   */
}
