<?php
/**
 * @file
 * catalyst_layout.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function catalyst_layout_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'catalyst_layout_admin';
  $view->description = 'Provides administration views for catalyst doctype entities.';
  $view->tag = 'default';
  $view->base_table = 'eck_catalyst';
  $view->human_name = 'catalyst_layout_admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Layouts';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'eck list catalyst layout entities';
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
    \'title\' => t(\'Create new layout\'),
    \'path\' => \'admin/structure/layout/add\',
    \'destination\' => \'admin/structure/layout\',
    \'access\' => \'eck add catalyst layout entities\',
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
  $handler->display->display_options['empty']['php']['php_output'] = '<?php print catalyst_admin_views_no_results($view, \'layout\', array(
  \'bundle\' => \'layout\',
  \'path\' => \'admin/structure/layout/add\',
  \'destination\' => \'admin/structure/layout\',
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
  $handler->display->display_options['fields']['php_2']['php_value'] = 'return catalyst_admin_eck_entity_link(\'layout\', $row->id, filter_xss_admin($row->title), \'edit\', \'admin/structure\', array(
  \'query\' => array(\'destination\' => \'admin/structure/layout\'),
));';
  $handler->display->display_options['fields']['php_2']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_2']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_2']['php_click_sortable'] = '';
  /* Field: Catalyst: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'eck_catalyst';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = 'Layout';
  $handler->display->display_options['fields']['title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_1']['alter']['text'] = '[php_2]';
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
  \'layout\', $row->id, t(\'edit\'), \'edit\', \'admin/structure\',
  array(\'query\' => array(\'destination\' => \'admin/structure/layout\'))
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
  \'layout\', $row->id, t(\'delete\'), \'delete\', \'admin/structure\',
  array(\'query\' => array(\'destination\' => \'admin/structure/layout\'))
);';
  $handler->display->display_options['fields']['php_1']['php_output'] = '<?php print $value; ?>';
  $handler->display->display_options['fields']['php_1']['use_php_click_sortable'] = '0';
  $handler->display->display_options['fields']['php_1']['php_click_sortable'] = '';
  /* Filter criterion: Catalyst: catalyst type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'eck_catalyst';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'layout' => 'layout',
  );
  /* Filter criterion: catalyst: Doctype (field_layout_doctype) */
  $handler->display->display_options['filters']['field_layout_doctype_target_id']['id'] = 'field_layout_doctype_target_id';
  $handler->display->display_options['filters']['field_layout_doctype_target_id']['table'] = 'field_data_field_layout_doctype';
  $handler->display->display_options['filters']['field_layout_doctype_target_id']['field'] = 'field_layout_doctype_target_id';
  $handler->display->display_options['filters']['field_layout_doctype_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_layout_doctype_target_id']['expose']['operator_id'] = 'field_layout_doctype_target_id_op';
  $handler->display->display_options['filters']['field_layout_doctype_target_id']['expose']['label'] = 'Doctype';
  $handler->display->display_options['filters']['field_layout_doctype_target_id']['expose']['operator'] = 'field_layout_doctype_target_id_op';
  $handler->display->display_options['filters']['field_layout_doctype_target_id']['expose']['identifier'] = 'field_layout_doctype_target_id';
  $handler->display->display_options['filters']['field_layout_doctype_target_id']['expose']['remember'] = TRUE;
  $handler->display->display_options['filters']['field_layout_doctype_target_id']['expose']['remember_roles'] = array(
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
  $handler->display->display_options['path'] = 'admin/structure/layout/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'LIst';
  $handler->display->display_options['menu']['weight'] = '-10';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Layouts';
  $handler->display->display_options['tab_options']['description'] = 'Create and manage layouts that are available to pages.';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Export */
  $handler = $view->new_display('views_data_export', 'Export', 'export_xml');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xml';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['transform'] = 1;
  $handler->display->display_options['style_options']['root_node'] = 'layouts';
  $handler->display->display_options['style_options']['item_node'] = 'layout';
  $handler->display->display_options['style_options']['no_entity_encode'] = array(
    'field_layout_content' => 'field_layout_content',
    'field_layout_css' => 'field_layout_css',
    'field_layout_js' => 'field_layout_js',
    'field_layout_page_title_pattern' => 'field_layout_page_title_pattern',
    'field_layout_preprocess' => 'field_layout_preprocess',
    'field_layout_html_head' => 'field_layout_html_head',
    'field_layout_onselect' => 'field_layout_onselect',
    'field_layout_ondeselect' => 'field_layout_ondeselect',
  );
  $handler->display->display_options['style_options']['cdata_wrapper'] = array(
    'field_layout_content' => 'field_layout_content',
    'field_layout_css' => 'field_layout_css',
    'field_layout_js' => 'field_layout_js',
    'field_layout_page_title_pattern' => 'field_layout_page_title_pattern',
    'field_layout_preprocess' => 'field_layout_preprocess',
    'field_layout_html_head' => 'field_layout_html_head',
    'field_layout_onselect' => 'field_layout_onselect',
    'field_layout_ondeselect' => 'field_layout_ondeselect',
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
  /* Field: catalyst: Content */
  $handler->display->display_options['fields']['field_layout_content']['id'] = 'field_layout_content';
  $handler->display->display_options['fields']['field_layout_content']['table'] = 'field_data_field_layout_content';
  $handler->display->display_options['fields']['field_layout_content']['field'] = 'field_layout_content';
  $handler->display->display_options['fields']['field_layout_content']['label'] = 'content';
  /* Field: catalyst: Doctype */
  $handler->display->display_options['fields']['field_layout_doctype']['id'] = 'field_layout_doctype';
  $handler->display->display_options['fields']['field_layout_doctype']['table'] = 'field_data_field_layout_doctype';
  $handler->display->display_options['fields']['field_layout_doctype']['field'] = 'field_layout_doctype';
  $handler->display->display_options['fields']['field_layout_doctype']['label'] = 'doctype';
  $handler->display->display_options['fields']['field_layout_doctype']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_layout_doctype']['settings'] = array(
    'link' => 0,
  );
  /* Field: catalyst: Custom CSS */
  $handler->display->display_options['fields']['field_layout_css']['id'] = 'field_layout_css';
  $handler->display->display_options['fields']['field_layout_css']['table'] = 'field_data_field_layout_css';
  $handler->display->display_options['fields']['field_layout_css']['field'] = 'field_layout_css';
  $handler->display->display_options['fields']['field_layout_css']['label'] = 'css_custom';
  /* Field: catalyst: Stylesheet Includes */
  $handler->display->display_options['fields']['field_layout_includes_css']['id'] = 'field_layout_includes_css';
  $handler->display->display_options['fields']['field_layout_includes_css']['table'] = 'field_data_field_layout_includes_css';
  $handler->display->display_options['fields']['field_layout_includes_css']['field'] = 'field_layout_includes_css';
  $handler->display->display_options['fields']['field_layout_includes_css']['label'] = 'css_includes';
  $handler->display->display_options['fields']['field_layout_includes_css']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_layout_includes_css']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_layout_includes_css']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_layout_includes_css']['separator'] = ',';
  /* Field: catalyst: Custom Javascript */
  $handler->display->display_options['fields']['field_layout_js']['id'] = 'field_layout_js';
  $handler->display->display_options['fields']['field_layout_js']['table'] = 'field_data_field_layout_js';
  $handler->display->display_options['fields']['field_layout_js']['field'] = 'field_layout_js';
  $handler->display->display_options['fields']['field_layout_js']['label'] = 'js_custom';
  /* Field: catalyst: Javascript Includes */
  $handler->display->display_options['fields']['field_layout_includes_js']['id'] = 'field_layout_includes_js';
  $handler->display->display_options['fields']['field_layout_includes_js']['table'] = 'field_data_field_layout_includes_js';
  $handler->display->display_options['fields']['field_layout_includes_js']['field'] = 'field_layout_includes_js';
  $handler->display->display_options['fields']['field_layout_includes_js']['label'] = 'js_includes';
  $handler->display->display_options['fields']['field_layout_includes_js']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_layout_includes_js']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_layout_includes_js']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_layout_includes_js']['separator'] = ',';
  /* Field: Field: Custom Files */
  $handler->display->display_options['fields']['field_catalyst_custom_files']['id'] = 'field_catalyst_custom_files';
  $handler->display->display_options['fields']['field_catalyst_custom_files']['table'] = 'field_data_field_catalyst_custom_files';
  $handler->display->display_options['fields']['field_catalyst_custom_files']['field'] = 'field_catalyst_custom_files';
  $handler->display->display_options['fields']['field_catalyst_custom_files']['label'] = 'files_custom';
  $handler->display->display_options['fields']['field_catalyst_custom_files']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_catalyst_custom_files']['type'] = 'catalyst_file_import_path';
  $handler->display->display_options['fields']['field_catalyst_custom_files']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_catalyst_custom_files']['separator'] = '|';
  /* Field: Field: Shared Files */
  $handler->display->display_options['fields']['field_catalyst_shared_files']['id'] = 'field_catalyst_shared_files';
  $handler->display->display_options['fields']['field_catalyst_shared_files']['table'] = 'field_data_field_catalyst_shared_files';
  $handler->display->display_options['fields']['field_catalyst_shared_files']['field'] = 'field_catalyst_shared_files';
  $handler->display->display_options['fields']['field_catalyst_shared_files']['label'] = 'files_shared';
  $handler->display->display_options['fields']['field_catalyst_shared_files']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_catalyst_shared_files']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_catalyst_shared_files']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_catalyst_shared_files']['separator'] = ',';
  /* Field: catalyst: Regions */
  $handler->display->display_options['fields']['field_layout_regions']['id'] = 'field_layout_regions';
  $handler->display->display_options['fields']['field_layout_regions']['table'] = 'field_data_field_layout_regions';
  $handler->display->display_options['fields']['field_layout_regions']['field'] = 'field_layout_regions';
  $handler->display->display_options['fields']['field_layout_regions']['label'] = 'regions';
  $handler->display->display_options['fields']['field_layout_regions']['click_sort_column'] = 'machine';
  $handler->display->display_options['fields']['field_layout_regions']['type'] = 'machine_both';
  $handler->display->display_options['fields']['field_layout_regions']['delta_offset'] = '0';
  /* Field: catalyst: Blocks */
  $handler->display->display_options['fields']['field_layout_blocks']['id'] = 'field_layout_blocks';
  $handler->display->display_options['fields']['field_layout_blocks']['table'] = 'field_data_field_layout_blocks';
  $handler->display->display_options['fields']['field_layout_blocks']['field'] = 'field_layout_blocks';
  $handler->display->display_options['fields']['field_layout_blocks']['label'] = 'block_placements';
  $handler->display->display_options['fields']['field_layout_blocks']['click_sort_column'] = 'block_id';
  $handler->display->display_options['fields']['field_layout_blocks']['delta_offset'] = '0';
  /* Field: catalyst: Add Blocks */
  $handler->display->display_options['fields']['field_catalyst_blocks_add']['id'] = 'field_catalyst_blocks_add';
  $handler->display->display_options['fields']['field_catalyst_blocks_add']['table'] = 'field_data_field_catalyst_blocks_add';
  $handler->display->display_options['fields']['field_catalyst_blocks_add']['field'] = 'field_catalyst_blocks_add';
  $handler->display->display_options['fields']['field_catalyst_blocks_add']['label'] = 'blocks_reference';
  $handler->display->display_options['fields']['field_catalyst_blocks_add']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_catalyst_blocks_add']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_catalyst_blocks_add']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_catalyst_blocks_add']['separator'] = ',';
  /* Field: catalyst: Page title pattern */
  $handler->display->display_options['fields']['field_layout_page_title_pattern']['id'] = 'field_layout_page_title_pattern';
  $handler->display->display_options['fields']['field_layout_page_title_pattern']['table'] = 'field_data_field_layout_page_title_pattern';
  $handler->display->display_options['fields']['field_layout_page_title_pattern']['field'] = 'field_layout_page_title_pattern';
  $handler->display->display_options['fields']['field_layout_page_title_pattern']['label'] = 'page_title_pattern';
  /* Field: catalyst: Preprocessing */
  $handler->display->display_options['fields']['field_layout_preprocess']['id'] = 'field_layout_preprocess';
  $handler->display->display_options['fields']['field_layout_preprocess']['table'] = 'field_data_field_layout_preprocess';
  $handler->display->display_options['fields']['field_layout_preprocess']['field'] = 'field_layout_preprocess';
  $handler->display->display_options['fields']['field_layout_preprocess']['label'] = 'preprocess_php';
  /* Field: catalyst: Custom HTML Head */
  $handler->display->display_options['fields']['field_layout_html_head']['id'] = 'field_layout_html_head';
  $handler->display->display_options['fields']['field_layout_html_head']['table'] = 'field_data_field_layout_html_head';
  $handler->display->display_options['fields']['field_layout_html_head']['field'] = 'field_layout_html_head';
  $handler->display->display_options['fields']['field_layout_html_head']['label'] = 'html_head';
  /* Field: catalyst: Enable Drupal processing */
  $handler->display->display_options['fields']['field_catalyst_drupal_processing']['id'] = 'field_catalyst_drupal_processing';
  $handler->display->display_options['fields']['field_catalyst_drupal_processing']['table'] = 'field_data_field_catalyst_drupal_processing';
  $handler->display->display_options['fields']['field_catalyst_drupal_processing']['field'] = 'field_catalyst_drupal_processing';
  $handler->display->display_options['fields']['field_catalyst_drupal_processing']['label'] = 'drupal_processing';
  /* Field: catalyst: Show messages */
  $handler->display->display_options['fields']['field_layout_show_messages']['id'] = 'field_layout_show_messages';
  $handler->display->display_options['fields']['field_layout_show_messages']['table'] = 'field_data_field_layout_show_messages';
  $handler->display->display_options['fields']['field_layout_show_messages']['field'] = 'field_layout_show_messages';
  $handler->display->display_options['fields']['field_layout_show_messages']['label'] = 'show_messages';
  $handler->display->display_options['fields']['field_layout_show_messages']['type'] = 'list_key';
  /* Field: catalyst: Drupal Stylesheets */
  $handler->display->display_options['fields']['field_layout_drupal_css']['id'] = 'field_layout_drupal_css';
  $handler->display->display_options['fields']['field_layout_drupal_css']['table'] = 'field_data_field_layout_drupal_css';
  $handler->display->display_options['fields']['field_layout_drupal_css']['field'] = 'field_layout_drupal_css';
  $handler->display->display_options['fields']['field_layout_drupal_css']['label'] = 'drupal_css_options';
  $handler->display->display_options['fields']['field_layout_drupal_css']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_layout_drupal_css']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_layout_drupal_css']['separator'] = ',';
  /* Field: catalyst: Drupal Javascript */
  $handler->display->display_options['fields']['field_layout_drupal_js']['id'] = 'field_layout_drupal_js';
  $handler->display->display_options['fields']['field_layout_drupal_js']['table'] = 'field_data_field_layout_drupal_js';
  $handler->display->display_options['fields']['field_layout_drupal_js']['field'] = 'field_layout_drupal_js';
  $handler->display->display_options['fields']['field_layout_drupal_js']['label'] = 'drupal_js_options';
  $handler->display->display_options['fields']['field_layout_drupal_js']['type'] = 'list_key';
  $handler->display->display_options['fields']['field_layout_drupal_js']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_layout_drupal_js']['separator'] = ',';
  /* Field: catalyst: Enable debugging */
  $handler->display->display_options['fields']['field_layout_debug']['id'] = 'field_layout_debug';
  $handler->display->display_options['fields']['field_layout_debug']['table'] = 'field_data_field_layout_debug';
  $handler->display->display_options['fields']['field_layout_debug']['field'] = 'field_layout_debug';
  $handler->display->display_options['fields']['field_layout_debug']['label'] = 'debug';
  /* Field: catalyst: On Select */
  $handler->display->display_options['fields']['field_layout_onselect']['id'] = 'field_layout_onselect';
  $handler->display->display_options['fields']['field_layout_onselect']['table'] = 'field_data_field_layout_onselect';
  $handler->display->display_options['fields']['field_layout_onselect']['field'] = 'field_layout_onselect';
  $handler->display->display_options['fields']['field_layout_onselect']['label'] = 'onselect';
  /* Field: catalyst: On DeSelect */
  $handler->display->display_options['fields']['field_layout_ondeselect']['id'] = 'field_layout_ondeselect';
  $handler->display->display_options['fields']['field_layout_ondeselect']['table'] = 'field_data_field_layout_ondeselect';
  $handler->display->display_options['fields']['field_layout_ondeselect']['field'] = 'field_layout_ondeselect';
  $handler->display->display_options['fields']['field_layout_ondeselect']['label'] = 'ondeselect';
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
    'layout' => 'layout',
  );
  $handler->display->display_options['path'] = 'admin/structure/layout/export.xml';
  $handler->display->display_options['displays'] = array(
    'cms_admin' => 'cms_admin',
    'default' => 0,
    'eck_admin' => 0,
  );
  $export['catalyst_layout_admin'] = $view;

  return $export;
}
