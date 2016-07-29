<?php

/**
 * @file
 * Catalyst import form and related callbacks.
 */

/**
 * Catalyst import form handler.
 */
function catalyst_import_form($form, &$form_state) {
  catalyst_form_load_include($form_state, 'import', 'export');
  $form['upload'] = array(
    '#type' => 'fieldset',
    '#title' => t('Import'),
  );
  $form['upload']['archive'] = array(
    '#type' => 'file',
    '#title' => t('Upload ZIP export'),
  );
  $form['upload']['degregister'] = array(
    '#type' => 'checkbox',
    '#title' => t('Deregister the import upon successful completion'),
    '#default_value' => 1,
  );
  $form['upload']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Upload import'),
  );
  return $form;
}

function catalyst_import_form_validate(&$form, &$form_state) {
  $validators = array('file_validate_extensions' => array('zip'));
  if ($file = file_save_upload('archive', $validators)) {
    $zip  = new ZipArchive;
    if ($zip->open(drupal_realpath($file->uri)) === TRUE) {
      $hash = md5(microtime());
      $tmp_uri = 'temporary://' . $hash;
      drupal_mkdir($tmp_uri);
      $tmp_dir = drupal_realpath($tmp_uri);
      if ($zip->extractTo($tmp_dir)) {
        $info = drupal_json_decode(file_get_contents($tmp_dir . '/catalyst.json'));
        if (!isset($info['migrations'])) {
          form_set_error('', t('Not a valid import'));
        }
        else {
          $form_state['tmp_dir'] = $tmp_dir;
          $groups = array_keys($info['groups']);
          $group = array_shift($groups);
          $dir = str_replace($hash, $group, $tmp_dir);
          $form_state['source_directory'] = rename($tmp_dir, $dir) ? $dir : $tmp_dir;
        }
      }
      else {
        form_set_error('', t('Failed to unpack the zip archive'));
      }
    }
    else {
      form_set_error('archive', t('Unable to open the zip file'));
    }
    file_delete($file);
  }
}

function catalyst_import_form_submit($form, &$form_state) {
  catalyst_include('import');
  catalyst_import($form_state['source_directory']);
  $info = catalyst_load_import($form_state['source_directory']);
  if ($form_state['values']['deregister']) {
    catalyst_deregister_import($info);
  }
}
