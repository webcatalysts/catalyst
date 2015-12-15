<?php

/**
 * @file
 */

/**
 * Implements hook_migrate_api().
 */
function catalyst_core_migrate_api() {
  return array(
    'api' => 2,
    'groups' => array(
      'catalyst_install' => array(
        'title' => t('Catalyst CMS Installation Imports'),
      ),
    ),
  );
}
