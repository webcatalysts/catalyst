<?php
/**
 * @file
 * base.inc
 */

abstract class BetterMigration extends DynamicMigration {

}

abstract class BetterMigrationBase extends DynamicMigration {

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
  public function __construct() {

    // Use the GROUP constant to define a migrations group to reduce the need
    // for constructors in subclasses.
    parent::__construct(MigrateGroup::getInstance($this::GROUP));

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
   * Needs commenting!!
   */
  const DATA_DIRECTORY = 'data';
  const DATA_DIRECTORY_SUBPATH = '';
  protected function dataDirectory() {
    // Derrive our data directory from the install profile
    $profile = drupal_get_profile();

    // Ensure we have a profile name to use
    if (empty($profile)) {
      throw new Exception(t('Empty $profile encountered in @class_name', array('@class_name' => get_class($this))));
    }

    $path = drupal_get_path('profile', $profile) . '/' . $this::DATA_DIRECTORY;

    if ($this::DATA_DIRECTORY_SUBPATH != '') {
      $path .= '/' . $this::DATA_DIRECTORY_SUBPATH;
    }
    return $path;
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

  protected $generateImages = FALSE;
  protected function generateImageCallback($value) {
    if (empty($value) && $this->generateImages && module_exists('devel_generate')) {
      module_load_include('inc', 'devel_generate', 'image.devel_generate');
      if ($image = devel_generate_image('png', '960x960', '960x960')) {
        $value = $image;
      }
    }
    elseif(!empty($value)) {
      $value = $this->dataDirectory() . '/' . $value;
    }
    return $value;
  }
}
