<?php

/**
 * @file
 * Internal functions used by menu_lockdown that are included only as needed.
 */

define('MENU_LOCKDOWN_BLACKLIST', 'blacklist');
define('MENU_LOCKDOWN_WHITELIST', 'whitelist');

/**
 * Check to see if menu_lockdown is unlocked.
 *
 * Allows the function of this module to be permanently disabled in
 * non-produciton environments or to be temporarily disabled in production
 * environments.
 *
 * @return
 *   Returns true if menu lockdown is disabled or temporarily unlocked for
 *   debugging.
 */
function menu_lockdown_unlocked() {
  // Check if Menu Lockdown is disabled (in code), if not check if debugging is
  // active.
  return menu_lockdown_disabled() || menu_lockdown_debug();
}

/**
 * Check a menu (router) path to see if it should be locked down.
 *
 * @param $path
 *   The menu path to check.
 * @return
 *   Returns true if the path should be locked-down, otherwise it returns false.
 */
function menu_lockdown_path($path) {
  $whitelist = implode("\n", menu_lockdown_paths(MENU_LOCKDOWN_WHITELIST));
  $blacklist = implode("\n", menu_lockdown_paths(MENU_LOCKDOWN_BLACKLIST));
  // Check that the path is not white-listed first, then check if the path is
  // blacklisted.
  return !drupal_match_path($path, $whitelist) && drupal_match_path($path, $blacklist);
}

/**
 * Helper function for retrieving the configured paths for the given list.
 *
 * @param $list
 *    The list of paths to return, either 'blacklist' or 'whitelist'.
 * @see menu_lockdown_suggestions().
 */
function menu_lockdown_paths($list) {
  // Prevent invoking menu_lockdown_suggestions() if the whitelist is configured.
  if ($result = variable_get('menu_lockdown_' . $list, FALSE)) {
    return $result;
  }
  return menu_lockdown_suggestions($list);
}

/**
 * Retrieve the suggested paths to lockdown.
 *
 * Modules can implement hook_menu_lockdown_suggestions() to provide suggested
 * paths to lockdown.
 *
 *  @param $list
 *    The list to return, either 'blacklist' or 'whitelist'.
 *  @return
 *    Returns an array of paths for the given $list.
 */
function menu_lockdown_suggestions($list) {
  // Use static caching to ensure module hooks are only invoked once
  $suggestions =& drupal_static(__FUNCTION__);
  if (!isset($suggestions)) {
    // Load hooks for core and contrib that are by defined in this module
    menu_lockdown_include_modules();
    $suggestions = module_invoke_all('menu_lockdown_suggestions');
    // Allow other modules to alter suggestions
    drupal_alter('menu_lockdown_suggestions', $suggestions);
  }
  // Ensure we return an array
  return isset($suggestions[$list]) ? (array)$suggestions[$list] : array();
}

/**
 * Load hooks for core and contrib modules that are defined in this module.
 */
function menu_lockdown_load_module_hooks() {
  // Use static caching to help ensure the processing here is only ran once per
  // request.
  static $modules_loaded = FALSE;
  if (!$modules_loaded) {
    $modules_loaded = TRUE;
    // Traverse all include files in this module's "modules" directory.
    $directory = drupal_get_path('module', 'menu_lockdown');
    // @todo Determine if the result of file_scan_directory should be cached.
    $includes = file_scan_directory($directory, '/.*\.inc$/');
    foreach ($includes AS $file_obj) {
      // Each file is named after the module it represents.
      if (module_exists($file->name)) {
        // Ensure that the module doesn't already provide Menu Lockdown hooks
        $hook = $file->name . '_menu_lockdown_suggestions';
        if (!function_exists($hook) && !function_exists($hook . '_alter')) {
          require_once $file->uri;
        }
      }
    }
  }
}
