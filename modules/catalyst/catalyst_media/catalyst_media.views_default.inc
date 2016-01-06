<?php
/**
 * @file
 * catalyst_media.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function catalyst_media_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'catalyst_file_admin';
  $view->description = 'Provides administration views for catalyst doctype entities.';
  $view->tag = 'default';
  $view->base_table = 'eck_catalyst';
  $view->human_name = 'catalyst_file_admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Files';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'eck list catalyst file entities';
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
    'php_2' => 'php_2',
    'title_1' => 'title_1',
    'field_media_type' => 'field_media_type',
    'field_media_machine' => 'field_media_machine',
    'created' => 'created',
    'changed' => 'changed',
    'php' => 'php',
    'php_1' => 'php',
    'field_media_path' => 'php',
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
    'php_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_media_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_media_machine' => array(
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
    'field_media_path' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
  $handler->display->display_options['header']['php']['php_output'] = '<?php
catalyst_include(\'views\', \'admin\');
print catalyst_admin_action_links(array(
  \'file-add\' => array(
    \'title\' => t(\'Create new file\'),
    \'path\' => \'admin/content/file/add\',
    \'destination\' => \'admin/content/file\',
    \'access\' => \'eck add catalyst file entities\',
  ),
)); ?>';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Description';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<div class="description">
  <p><strong>Need description</strong></p>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* No results behavior: Global: PHP */
  $handler->display->display_options['empty']['php']['id'] = 'php';
  $handler->display->display_options['empty']['php']['table'] = 'views';
  $handler->display->display_options['empty']['php']['field'] = 'php';
  $handler->display->display_options['empty']['php']['empty'] = TRUE;
  $handler->display->display_options['empty']['php']['php_output'] = '<?php
catalyst_include(\'views\', \'admin\');
print catalyst_admin_views_no_results($view, \'file\', array(
  \'bundle\' => \'file\',
  \'path\' => \'admin/content/file/add\',
  \'destination\' => \'admin/content/file\',
)); ?>';
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
      'label' => 'Delete layout',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'layout::field_layout_drupal_js' => 'layout::field_layout_drupal_js',
          'layout::field_drupal_css' => 'layout::field_drupal_css',
          'layout::field_layout_drupal_processing' => 'layout::field_layout_drupal_processing',
          'layout::field_enable_debugging' => 'layout::field_enable_debugging',
          'layout::field_layout_page_title_pattern' => 'layout::field_layout_page_title_pattern',
          'layout::field_layout_show_messages' => 'layout::field_layout_show_messages',
          'layout::field_layout_doctype' => 'layout::field_layout_doctype',
        ),
      ),
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
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Title Link';
  $handler->display->display_options['fields']['php_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_value'] = 'catalyst_include(\'views\', \'admin\');
return catalyst_admin_eck_entity_link(\'file\', $row->id, filter_xss_admin($row->title), \'edit\', \'admin/content\', array(
  \'query\' => array(\'destination\' => \'admin/content/file\'),
));';
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Catalyst: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'eck_catalyst';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = 'File';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '[php_2]';
  /* Field: catalyst: Type */
  $handler->display->display_options['fields']['field_media_type']['id'] = 'field_media_type';
  $handler->display->display_options['fields']['field_media_type']['table'] = 'field_data_field_media_type';
  $handler->display->display_options['fields']['field_media_type']['field'] = 'field_media_type';
  /* Field: catalyst: Machine name */
  $handler->display->display_options['fields']['field_media_machine']['id'] = 'field_media_machine';
  $handler->display->display_options['fields']['field_media_machine']['table'] = 'field_data_field_media_machine';
  $handler->display->display_options['fields']['field_media_machine']['field'] = 'field_media_machine';
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
  $handler->display->display_options['fields']['php']['php_value'] = 'catalyst_include(\'views\', \'admin\');
return catalyst_admin_eck_entity_link(
  \'file\', $row->id, t(\'edit\'), \'edit\', \'admin/content\',
  array(\'query\' => array(\'destination\' => \'admin/content/file\'))
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
  $handler->display->display_options['fields']['php_1']['php_value'] = 'catalyst_include(\'views\', \'admin\');
return catalyst_admin_eck_entity_link(
  \'file\', $row->id, t(\'delete\'), \'delete\', \'admin/content\',
  array(\'query\' => array(\'destination\' => \'admin/content/file\'))
);';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: catalyst: Path */
  $handler->display->display_options['fields']['field_media_path']['id'] = 'field_media_path';
  $handler->display->display_options['fields']['field_media_path']['table'] = 'field_data_field_media_path';
  $handler->display->display_options['fields']['field_media_path']['field'] = 'field_media_path';
  $handler->display->display_options['fields']['field_media_path']['label'] = 'View';
  $handler->display->display_options['fields']['field_media_path']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_media_path']['alter']['text'] = 'view';
  $handler->display->display_options['fields']['field_media_path']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_media_path']['alter']['path'] = '[field_media_path]';
  $handler->display->display_options['fields']['field_media_path']['alter']['target'] = '_blank';
  /* Filter criterion: Catalyst: catalyst type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_catalyst';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'file' => 'file',
  );
  /* Filter criterion: catalyst: Type (field_media_type) */
  $handler->display->display_options['filters']['field_media_type_value']['id'] = 'field_media_type_value';
  $handler->display->display_options['filters']['field_media_type_value']['table'] = 'field_data_field_media_type';
  $handler->display->display_options['filters']['field_media_type_value']['field'] = 'field_media_type_value';
  $handler->display->display_options['filters']['field_media_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_media_type_value']['expose']['operator_id'] = 'field_media_type_value_op';
  $handler->display->display_options['filters']['field_media_type_value']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_media_type_value']['expose']['operator'] = 'field_media_type_value_op';
  $handler->display->display_options['filters']['field_media_type_value']['expose']['identifier'] = 'field_media_type_value';
  $handler->display->display_options['filters']['field_media_type_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_media_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    3 => 0,
  );

  /* Display: ECK */
  $handler = $view->new_display('page', 'ECK', 'eck_admin');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['path'] = 'admin/structure/entity-type/catalyst/layout/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['description'] = 'Manage the layouts available to pages.';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Layouts';
  $handler->display->display_options['tab_options']['description'] = 'Create and manage layout entities';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Admin */
  $handler = $view->new_display('page', 'Admin', 'cms_admin');
  $handler->display->display_options['path'] = 'admin/content/file/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'LIst';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Files';
  $handler->display->display_options['tab_options']['description'] = 'Add and manage media files';
  $handler->display->display_options['tab_options']['weight'] = '2';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $export['catalyst_file_admin'] = $view;

  $view = new view();
  $view->name = 'catalyst_javascript_admin';
  $view->description = 'Provides administration views for catalyst doctype entities.';
  $view->tag = 'default';
  $view->base_table = 'eck_catalyst';
  $view->human_name = 'catalyst_javascript_admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Javascripts';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'eck list catalyst stylesheet entities';
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
    'php_2' => 'php_2',
    'title_1' => 'title_1',
    'field_javascript_machine' => 'field_javascript_machine',
    'field_media_type' => 'field_media_type',
    'field_javascript_scope' => 'field_javascript_scope',
    'created' => 'created',
    'changed' => 'changed',
    'php' => 'php',
    'php_1' => 'php',
    'field_media_path' => 'php',
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
    'php_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_javascript_machine' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_media_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_javascript_scope' => array(
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
    'field_media_path' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
  $handler->display->display_options['header']['php']['php_output'] = '<?php
catalyst_include(\'views\', \'admin\');
print catalyst_admin_action_links(array(
  \'javascript-add\' => array(
    \'title\' => t(\'Create new javascript\'),
    \'path\' => \'admin/structure/javascript/add\',
    \'destination\' => \'admin/structure/javascript\',
    \'access\' => \'eck add catalyst javascript entities\',
  ),
)); ?>';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Description';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<div class="description">
  <p><strong>Need description</strong></p>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* No results behavior: Global: PHP */
  $handler->display->display_options['empty']['php']['id'] = 'php';
  $handler->display->display_options['empty']['php']['table'] = 'views';
  $handler->display->display_options['empty']['php']['field'] = 'php';
  $handler->display->display_options['empty']['php']['empty'] = TRUE;
  $handler->display->display_options['empty']['php']['php_output'] = '<?php
catalyst_include(\'views\', \'admin\');
print catalyst_admin_views_no_results($view, \'javascripts\', array(
  \'bundle\' => \'javascript\',
  \'path\' => \'admin/structure/javascript/add\',
  \'destination\' => \'admin/structure/javascript\',
)); ?>';
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
      'label' => 'Delete javascript',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'layout::field_layout_drupal_js' => 'layout::field_layout_drupal_js',
          'layout::field_drupal_css' => 'layout::field_drupal_css',
          'layout::field_layout_page_title_pattern' => 'layout::field_layout_page_title_pattern',
          'layout::field_layout_show_messages' => 'layout::field_layout_show_messages',
          'layout::field_layout_doctype' => 'layout::field_layout_doctype',
        ),
      ),
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
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Title Link';
  $handler->display->display_options['fields']['php_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_value'] = 'catalyst_include(\'views\', \'admin\');
return catalyst_admin_eck_entity_link(\'javascript\', $row->id, filter_xss_admin($row->title), \'edit\', \'admin/structure\', array(
  \'query\' => array(\'destination\' => \'admin/structure/javascript\'),
));';
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Catalyst: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'eck_catalyst';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = 'Javascript';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '[php_2]';
  /* Field: catalyst: Type */
  $handler->display->display_options['fields']['field_media_type']['id'] = 'field_media_type';
  $handler->display->display_options['fields']['field_media_type']['table'] = 'field_data_field_media_type';
  $handler->display->display_options['fields']['field_media_type']['field'] = 'field_media_type';
  /* Field: catalyst: Scope */
  $handler->display->display_options['fields']['field_javascript_scope']['id'] = 'field_javascript_scope';
  $handler->display->display_options['fields']['field_javascript_scope']['table'] = 'field_data_field_javascript_scope';
  $handler->display->display_options['fields']['field_javascript_scope']['field'] = 'field_javascript_scope';
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
  $handler->display->display_options['fields']['php']['php_value'] = 'catalyst_include(\'views\', \'admin\');
return catalyst_admin_eck_entity_link(
  \'javascript\', $row->id, t(\'edit\'), \'edit\', \'admin/structure\',
  array(\'query\' => array(\'destination\' => \'admin/structure/javascript\'))
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
  $handler->display->display_options['fields']['php_1']['php_value'] = 'catalyst_include(\'views\', \'admin\');
return catalyst_admin_eck_entity_link(
  \'javascript\', $row->id, t(\'delete\'), \'delete\', \'admin/structure\',
  array(\'query\' => array(\'destination\' => \'admin/structure/javascript\'))
);';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: catalyst: Path */
  $handler->display->display_options['fields']['field_media_path']['id'] = 'field_media_path';
  $handler->display->display_options['fields']['field_media_path']['table'] = 'field_data_field_media_path';
  $handler->display->display_options['fields']['field_media_path']['field'] = 'field_media_path';
  $handler->display->display_options['fields']['field_media_path']['label'] = 'View';
  $handler->display->display_options['fields']['field_media_path']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_media_path']['alter']['text'] = 'view';
  $handler->display->display_options['fields']['field_media_path']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_media_path']['alter']['path'] = '[field_media_path]';
  $handler->display->display_options['fields']['field_media_path']['alter']['target'] = '_blank';
  /* Filter criterion: Catalyst: catalyst type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_catalyst';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'javascript' => 'javascript',
  );
  /* Filter criterion: catalyst: Type (field_media_type) */
  $handler->display->display_options['filters']['field_media_type_value']['id'] = 'field_media_type_value';
  $handler->display->display_options['filters']['field_media_type_value']['table'] = 'field_data_field_media_type';
  $handler->display->display_options['filters']['field_media_type_value']['field'] = 'field_media_type_value';
  $handler->display->display_options['filters']['field_media_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_media_type_value']['expose']['operator_id'] = 'field_media_type_value_op';
  $handler->display->display_options['filters']['field_media_type_value']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_media_type_value']['expose']['operator'] = 'field_media_type_value_op';
  $handler->display->display_options['filters']['field_media_type_value']['expose']['identifier'] = 'field_media_type_value';
  $handler->display->display_options['filters']['field_media_type_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_media_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: catalyst: Scope (field_javascript_scope) */
  $handler->display->display_options['filters']['field_javascript_scope_value']['id'] = 'field_javascript_scope_value';
  $handler->display->display_options['filters']['field_javascript_scope_value']['table'] = 'field_data_field_javascript_scope';
  $handler->display->display_options['filters']['field_javascript_scope_value']['field'] = 'field_javascript_scope_value';
  $handler->display->display_options['filters']['field_javascript_scope_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_javascript_scope_value']['expose']['operator_id'] = 'field_javascript_scope_value_op';
  $handler->display->display_options['filters']['field_javascript_scope_value']['expose']['label'] = 'Scope';
  $handler->display->display_options['filters']['field_javascript_scope_value']['expose']['operator'] = 'field_javascript_scope_value_op';
  $handler->display->display_options['filters']['field_javascript_scope_value']['expose']['identifier'] = 'field_javascript_scope_value';
  $handler->display->display_options['filters']['field_javascript_scope_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_javascript_scope_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    3 => 0,
  );

  /* Display: ECK */
  $handler = $view->new_display('page', 'ECK', 'eck_admin');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['path'] = 'admin/structure/entity-type/catalyst/layout/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['description'] = 'Manage the layouts available to pages.';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Layouts';
  $handler->display->display_options['tab_options']['description'] = 'Create and manage layout entities';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Admin */
  $handler = $view->new_display('page', 'Admin', 'cms_admin');
  $handler->display->display_options['path'] = 'admin/structure/javascript/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'LIst';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Javascripts';
  $handler->display->display_options['tab_options']['description'] = 'Create and manage javascripts';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $export['catalyst_javascript_admin'] = $view;

  $view = new view();
  $view->name = 'catalyst_stylesheet_admin';
  $view->description = 'Provides administration views for catalyst doctype entities.';
  $view->tag = 'default';
  $view->base_table = 'eck_catalyst';
  $view->human_name = 'catalyst_stylesheet_admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Stylesheets';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'eck list catalyst stylesheet entities';
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
    'php_2' => 'php_2',
    'title_1' => 'title_1',
    'field_media_type' => 'field_media_type',
    'field_stylesheet_media' => 'field_stylesheet_media',
    'created' => 'created',
    'changed' => 'changed',
    'php' => 'php',
    'php_1' => 'php',
    'field_media_path' => 'php',
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
    'php_2' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_media_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_stylesheet_media' => array(
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
    'field_media_path' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
  $handler->display->display_options['header']['php']['php_output'] = '<?php
catalyst_include(\'views\', \'admin\');
print catalyst_admin_action_links(array(
  \'doctype-add\' => array(
    \'title\' => t(\'Create new stylesheet\'),
    \'path\' => \'admin/structure/stylesheet/add\',
    \'destination\' => \'admin/structure/stylesheet\',
    \'access\' => \'eck add catalyst stylesheet entities\',
  ),
)); ?>';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Description';
  $handler->display->display_options['header']['area']['empty'] = TRUE;
  $handler->display->display_options['header']['area']['content'] = '<div class="description">
  <p><strong>Need description</strong></p>
</div>';
  $handler->display->display_options['header']['area']['format'] = 'php_code';
  /* No results behavior: Global: PHP */
  $handler->display->display_options['empty']['php']['id'] = 'php';
  $handler->display->display_options['empty']['php']['table'] = 'views';
  $handler->display->display_options['empty']['php']['field'] = 'php';
  $handler->display->display_options['empty']['php']['empty'] = TRUE;
  $handler->display->display_options['empty']['php']['php_output'] = '<?php
catalyst_include(\'views\', \'admin\');
print catalyst_admin_views_no_results($view, \'stylesheets\', array(
  \'bundle\' => \'stylesheet\',
  \'path\' => \'admin/structure/stylesheet/add\',
  \'destination\' => \'admin/structure/stylesheet\',
)); ?>';
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
      'label' => 'Delete stylesheet',
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'postpone_processing' => 0,
      'skip_confirmation' => 0,
      'override_label' => 0,
      'label' => '',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          'layout::field_layout_drupal_js' => 'layout::field_layout_drupal_js',
          'layout::field_drupal_css' => 'layout::field_drupal_css',
          'layout::field_layout_page_title_pattern' => 'layout::field_layout_page_title_pattern',
          'layout::field_layout_show_messages' => 'layout::field_layout_show_messages',
          'layout::field_layout_doctype' => 'layout::field_layout_doctype',
        ),
      ),
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
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  /* Field: Global: PHP */
  $handler->display->display_options['fields']['php_2']['id'] = 'php_2';
  $handler->display->display_options['fields']['php_2']['table'] = 'views';
  $handler->display->display_options['fields']['php_2']['field'] = 'php';
  $handler->display->display_options['fields']['php_2']['label'] = 'Title Link';
  $handler->display->display_options['fields']['php_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['php_2']['use_php_setup'] = 0;
  $handler->display->display_options['fields']['php_2']['php_value'] = 'catalyst_include(\'views\', \'admin\');
return catalyst_admin_eck_entity_link(\'stylesheet\', $row->id, filter_xss_admin($row->title), \'edit\', \'admin/structure\', array(
  \'query\' => array(\'destination\' => \'admin/structure/layout\'),
));';
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Catalyst: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'eck_catalyst';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = 'Stylesheet';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '[php_2]';
  /* Field: catalyst: Type */
  $handler->display->display_options['fields']['field_media_type']['id'] = 'field_media_type';
  $handler->display->display_options['fields']['field_media_type']['table'] = 'field_data_field_media_type';
  $handler->display->display_options['fields']['field_media_type']['field'] = 'field_media_type';
  /* Field: catalyst: Media */
  $handler->display->display_options['fields']['field_stylesheet_media']['id'] = 'field_stylesheet_media';
  $handler->display->display_options['fields']['field_stylesheet_media']['table'] = 'field_data_field_stylesheet_media';
  $handler->display->display_options['fields']['field_stylesheet_media']['field'] = 'field_stylesheet_media';
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
  $handler->display->display_options['fields']['php']['php_value'] = 'catalyst_include(\'views\', \'admin\');
return catalyst_admin_eck_entity_link(
  \'stylesheet\', $row->id, t(\'edit\'), \'edit\', \'admin/structure\',
  array(\'query\' => array(\'destination\' => \'admin/structure/stylesheet\'))
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
  $handler->display->display_options['fields']['php_1']['php_value'] = 'catalyst_include(\'views\', \'admin\');
return catalyst_admin_eck_entity_link(
  \'stylesheet\', $row->id, t(\'delete\'), \'delete\', \'admin/structure\',
  array(\'query\' => array(\'destination\' => \'admin/structure/stylesheet\'))
);';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Field: catalyst: Path */
  $handler->display->display_options['fields']['field_media_path']['id'] = 'field_media_path';
  $handler->display->display_options['fields']['field_media_path']['table'] = 'field_data_field_media_path';
  $handler->display->display_options['fields']['field_media_path']['field'] = 'field_media_path';
  $handler->display->display_options['fields']['field_media_path']['label'] = 'View';
  $handler->display->display_options['fields']['field_media_path']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_media_path']['alter']['text'] = 'view';
  $handler->display->display_options['fields']['field_media_path']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_media_path']['alter']['path'] = '[field_media_path]';
  $handler->display->display_options['fields']['field_media_path']['alter']['target'] = '_blank';
  /* Filter criterion: Catalyst: catalyst type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_catalyst';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'stylesheet' => 'stylesheet',
  );
  /* Filter criterion: catalyst: Type (field_media_type) */
  $handler->display->display_options['filters']['field_media_type_value']['id'] = 'field_media_type_value';
  $handler->display->display_options['filters']['field_media_type_value']['table'] = 'field_data_field_media_type';
  $handler->display->display_options['filters']['field_media_type_value']['field'] = 'field_media_type_value';
  $handler->display->display_options['filters']['field_media_type_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_media_type_value']['expose']['operator_id'] = 'field_media_type_value_op';
  $handler->display->display_options['filters']['field_media_type_value']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['field_media_type_value']['expose']['operator'] = 'field_media_type_value_op';
  $handler->display->display_options['filters']['field_media_type_value']['expose']['identifier'] = 'field_media_type_value';
  $handler->display->display_options['filters']['field_media_type_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_media_type_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    3 => 0,
  );
  /* Filter criterion: catalyst: Media (field_stylesheet_media) */
  $handler->display->display_options['filters']['field_stylesheet_media_value']['id'] = 'field_stylesheet_media_value';
  $handler->display->display_options['filters']['field_stylesheet_media_value']['table'] = 'field_data_field_stylesheet_media';
  $handler->display->display_options['filters']['field_stylesheet_media_value']['field'] = 'field_stylesheet_media_value';
  $handler->display->display_options['filters']['field_stylesheet_media_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_stylesheet_media_value']['expose']['operator_id'] = 'field_stylesheet_media_value_op';
  $handler->display->display_options['filters']['field_stylesheet_media_value']['expose']['label'] = 'Media';
  $handler->display->display_options['filters']['field_stylesheet_media_value']['expose']['operator'] = 'field_stylesheet_media_value_op';
  $handler->display->display_options['filters']['field_stylesheet_media_value']['expose']['identifier'] = 'field_stylesheet_media_value';
  $handler->display->display_options['filters']['field_stylesheet_media_value']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_stylesheet_media_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    6 => 0,
    5 => 0,
    4 => 0,
    7 => 0,
    3 => 0,
  );

  /* Display: ECK */
  $handler = $view->new_display('page', 'ECK', 'eck_admin');
  $handler->display->display_options['enabled'] = FALSE;
  $handler->display->display_options['path'] = 'admin/structure/entity-type/catalyst/layout/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['description'] = 'Manage the layouts available to pages.';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Layouts';
  $handler->display->display_options['tab_options']['description'] = 'Create and manage layout entities';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Admin */
  $handler = $view->new_display('page', 'Admin', 'cms_admin');
  $handler->display->display_options['path'] = 'admin/structure/stylesheet/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'LIst';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Stylesheets';
  $handler->display->display_options['tab_options']['description'] = 'Create and manage stylesheets';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';
  $export['catalyst_stylesheet_admin'] = $view;

  return $export;
}
