<?php
/**
 * @file
 * catalyst_doctype.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function catalyst_doctype_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'catalyst_doctype_admin';
  $view->description = 'Provides administration views for catalyst doctype entities.';
  $view->tag = 'default';
  $view->base_table = 'eck_catalyst';
  $view->human_name = 'catalyst_doctype_admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Doctypes';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'eck list catalyst doctype entities';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'id' => 'id',
    'title' => 'title',
    'created' => 'created',
    'changed' => 'changed',
    'php' => 'php',
    'php_1' => 'php',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'id' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'php' => array(
      'align' => '',
      'separator' => '&nbsp;|&nbsp;',
      'empty_column' => 0,
    ),
    'php_1' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: PHP */
  $handler->display->display_options['header']['php']['id'] = 'php';
  $handler->display->display_options['header']['php']['table'] = 'views';
  $handler->display->display_options['header']['php']['field'] = 'php';
  $handler->display->display_options['header']['php']['label'] = 'Action Links';
  $handler->display->display_options['header']['php']['empty'] = TRUE;
  $handler->display->display_options['header']['php']['php_output'] = '<?php print catalyst_admin_action_links(array(
  \'doctype-add\' => array(
    \'title\' => t(\'Create new doctype\'),
    \'path\' => \'admin/structure/doctype/add\',
    \'destination\' => \'admin/structure/doctype\',
    \'access\' => \'eck add catalyst doctype entities\',
  ),
)); ?>';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Description';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<div class="description">
  <p><?php print t(\'Doctypes offer a flexible way to create a diverse set of web responses including various forms of HTML, XML, JSON, etc.\') ?></p>
  <p><em><?php print t(\'Doctypes are referenced by layouts and do nothing on their own.\'); ?></em></p>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* No results behavior: Global: PHP */
  $handler->display->display_options['empty']['php']['id'] = 'php';
  $handler->display->display_options['empty']['php']['table'] = 'views';
  $handler->display->display_options['empty']['php']['field'] = 'php';
  $handler->display->display_options['empty']['php']['empty'] = TRUE;
  $handler->display->display_options['empty']['php']['php_output'] = '<?php if (empty($view->exposed_input)): ?>
<p><?php print t(\'No doctypes have been created yet.\'); ?></p>
<?php else: ?>
<p><?php print t(\'No doctypes were found that match your current search filters.\'); ?></p>
<?php endif; ?>';
  /* Field: Bulk operations: Catalyst */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'eck_catalyst';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['row_clickable'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete doctype',
    ),
  );
  /* Field: Catalyst: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_catalyst';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'ID';
  /* Field: Catalyst: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_catalyst';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Doctype';
  /* Field: Catalyst: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'eck_catalyst';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'm/d/Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Catalyst: Changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'eck_catalyst';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = '2';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php']['id'] = 'php';
  $handler->display->display_options['fields']['php']['table'] = 'views';
  $handler->display->display_options['fields']['php']['field'] = 'php';
  $handler->display->display_options['fields']['php']['label'] = 'Actions';
  $handler->display->display_options['fields']['php']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['php']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php']['php_value'] = 'return catalyst_admin_eck_entity_link(
  \'doctype\', $row->id, t(\'edit\'), \'edit\', \'admin/structure\',
  array(\'query\' => array(\'destination\' => \'admin/structure/doctype\'))
);';
  $handler->display->display_options['fields']['php']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php']['php_click_sortable'] = '';
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_1']['id'] = 'php_1';
  $handler->display->display_options['fields']['php_1']['table'] = 'views';
  $handler->display->display_options['fields']['php_1']['field'] = 'php';
  $handler->display->display_options['fields']['php_1']['label'] = 'Delete';
  $handler->display->display_options['fields']['php_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['php_1']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_1']['php_value'] = 'return catalyst_admin_eck_entity_link(
  \'doctype\', $row->id, t(\'delete\'), \'delete\', \'admin/structure\',
  array(\'query\' => array(\'destination\' => \'admin/structure/doctype\'))
);';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Filter criterion: Catalyst: catalyst type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_catalyst';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'doctype' => 'doctype',
  );

  /* Display: ECK */
  $handler = $view->new_display('page', 'ECK', 'eck_admin');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['path'] = 'admin/structure/entity-type/catalyst/doctype/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['description'] = 'Manage the doctypes available to layouts.';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Doctypes';
  $handler->display->display_options['tab_options']['description'] = 'Create and manage doctype entities';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Admin */
  $handler = $view->new_display('page', 'Admin', 'cms_admin');
  $handler->display->display_options['path'] = 'admin/structure/doctype/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'LIst';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Document types';
  $handler->display->display_options['tab_options']['description'] = 'Create and manage doctypes that are available to layouts.';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'export_xml');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xml';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['transform'] = 1;
  $handler->display->display_options['style_options']['root_node'] = 'doctypes';
  $handler->display->display_options['style_options']['item_node'] = 'doctype';
  $handler->display->display_options['style_options']['no_entity_encode'] = array(
    'field_doctype_content' => 'field_doctype_content',
    'field_doctype_preprocess' => 'field_doctype_preprocess',
    'field_doctype_onselect' => 'field_doctype_onselect',
    'field_doctype_ondeselect' => 'field_doctype_ondeselect',
  );
  $handler->display->display_options['style_options']['cdata_wrapper'] = array(
    'field_doctype_content' => 'field_doctype_content',
    'field_doctype_preprocess' => 'field_doctype_preprocess',
    'field_doctype_onselect' => 'field_doctype_onselect',
    'field_doctype_ondeselect' => 'field_doctype_ondeselect',
  );
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Catalyst: Id */
  $handler->display->display_options['fields']['id']['id'] = 'id';
  $handler->display->display_options['fields']['id']['table'] = 'eck_catalyst';
  $handler->display->display_options['fields']['id']['field'] = 'id';
  $handler->display->display_options['fields']['id']['label'] = 'id';
  $handler->display->display_options['fields']['id']['separator'] = '';
  /* Field: Catalyst: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'eck_catalyst';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  /* Field: catalyst: HTTP Content-Type */
  $handler->display->display_options['fields']['field_doctype_content_type']['id'] = 'field_doctype_content_type';
  $handler->display->display_options['fields']['field_doctype_content_type']['table'] = 'field_data_field_doctype_content_type';
  $handler->display->display_options['fields']['field_doctype_content_type']['field'] = 'field_doctype_content_type';
  $handler->display->display_options['fields']['field_doctype_content_type']['label'] = 'http_content_type';
  /* Field: catalyst: Character Set */
  $handler->display->display_options['fields']['field_doctype_charset']['id'] = 'field_doctype_charset';
  $handler->display->display_options['fields']['field_doctype_charset']['table'] = 'field_data_field_doctype_charset';
  $handler->display->display_options['fields']['field_doctype_charset']['field'] = 'field_doctype_charset';
  $handler->display->display_options['fields']['field_doctype_charset']['label'] = 'charset';
  /* Field: catalyst: Enable Drupal processing */
  $handler->display->display_options['fields']['field_catalyst_drupal_processing']['id'] = 'field_catalyst_drupal_processing';
  $handler->display->display_options['fields']['field_catalyst_drupal_processing']['table'] = 'field_data_field_catalyst_drupal_processing';
  $handler->display->display_options['fields']['field_catalyst_drupal_processing']['field'] = 'field_catalyst_drupal_processing';
  $handler->display->display_options['fields']['field_catalyst_drupal_processing']['label'] = 'drupal_processing';
  $handler->display->display_options['fields']['field_catalyst_drupal_processing']['type'] = 'list_key';
  /* Field: catalyst: Content */
  $handler->display->display_options['fields']['field_doctype_content']['id'] = 'field_doctype_content';
  $handler->display->display_options['fields']['field_doctype_content']['table'] = 'field_data_field_doctype_content';
  $handler->display->display_options['fields']['field_doctype_content']['field'] = 'field_doctype_content';
  $handler->display->display_options['fields']['field_doctype_content']['label'] = 'content';
  /* Field: catalyst: Preprocessing */
  $handler->display->display_options['fields']['field_doctype_preprocess']['id'] = 'field_doctype_preprocess';
  $handler->display->display_options['fields']['field_doctype_preprocess']['table'] = 'field_data_field_doctype_preprocess';
  $handler->display->display_options['fields']['field_doctype_preprocess']['field'] = 'field_doctype_preprocess';
  $handler->display->display_options['fields']['field_doctype_preprocess']['label'] = 'preprocess_php';
  /* Field: catalyst: On Select */
  $handler->display->display_options['fields']['field_doctype_onselect']['id'] = 'field_doctype_onselect';
  $handler->display->display_options['fields']['field_doctype_onselect']['table'] = 'field_data_field_doctype_onselect';
  $handler->display->display_options['fields']['field_doctype_onselect']['field'] = 'field_doctype_onselect';
  $handler->display->display_options['fields']['field_doctype_onselect']['label'] = 'onselect';
  /* Field: catalyst: On DeSelect */
  $handler->display->display_options['fields']['field_doctype_ondeselect']['id'] = 'field_doctype_ondeselect';
  $handler->display->display_options['fields']['field_doctype_ondeselect']['table'] = 'field_data_field_doctype_ondeselect';
  $handler->display->display_options['fields']['field_doctype_ondeselect']['field'] = 'field_doctype_ondeselect';
  $handler->display->display_options['fields']['field_doctype_ondeselect']['label'] = 'ondeselect';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: IDs */
  $handler->display->display_options['arguments']['id']['id'] = 'id';
  $handler->display->display_options['arguments']['id']['table'] = 'eck_catalyst';
  $handler->display->display_options['arguments']['id']['field'] = 'id';
  $handler->display->display_options['arguments']['id']['ui_name'] = 'IDs';
  $handler->display->display_options['arguments']['id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['id']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['id']['default_argument_options']['code'] = 'return isset($_REQUEST[\'ids\']) ? $_REQUEST[\'ids\'] : NULL;';
  $handler->display->display_options['arguments']['id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['id']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['id']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['id']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Catalyst: catalyst type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_catalyst';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'doctype' => 'doctype',
  );
  $handler->display->display_options['path'] = 'admin/structure/doctype/export.xml';
  $handler->display->display_options['displays'] = array(
    'cms_admin' => 'cms_admin',
    'default' => 0,
    'eck_admin' => 0,
  );
  $export['catalyst_doctype_admin'] = $view;

  return $export;
}
