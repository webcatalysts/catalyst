<?php
/**
 * @file
 * catalyst_page.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function catalyst_page_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'catalyst_cpage_admin';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'catalyst_cpage_admin';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access content overview';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cpage' => 'cpage',
  );

  /* Display: Export */
  $handler = $view->new_display('views_data_export', 'Export', 'export_xml');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xml';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['transform'] = 1;
  $handler->display->display_options['style_options']['root_node'] = 'pages';
  $handler->display->display_options['style_options']['item_node'] = 'page';
  $handler->display->display_options['style_options']['no_entity_encode'] = array(
    'field_cpage_content' => 'field_cpage_content',
    'field_cpage_custom_css' => 'field_cpage_custom_css',
    'field_cpage_custom_js' => 'field_cpage_custom_js',
    'field_cpage_head' => 'field_cpage_head',
    'field_cpage_preprocess' => 'field_cpage_preprocess',
  );
  $handler->display->display_options['style_options']['cdata_wrapper'] = array(
    'field_cpage_content' => 'field_cpage_content',
    'field_cpage_custom_css' => 'field_cpage_custom_css',
    'field_cpage_custom_js' => 'field_cpage_custom_js',
    'field_cpage_head' => 'field_cpage_head',
    'field_cpage_preprocess' => 'field_cpage_preprocess',
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Layout */
  $handler->display->display_options['fields']['field_cpage_layout']['id'] = 'field_cpage_layout';
  $handler->display->display_options['fields']['field_cpage_layout']['table'] = 'field_data_field_cpage_layout';
  $handler->display->display_options['fields']['field_cpage_layout']['field'] = 'field_cpage_layout';
  $handler->display->display_options['fields']['field_cpage_layout']['label'] = 'layout';
  $handler->display->display_options['fields']['field_cpage_layout']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_cpage_layout']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'path';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'status';
  $handler->display->display_options['fields']['status']['type'] = 'boolean';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Content */
  $handler->display->display_options['fields']['field_cpage_content']['id'] = 'field_cpage_content';
  $handler->display->display_options['fields']['field_cpage_content']['table'] = 'field_data_field_cpage_content';
  $handler->display->display_options['fields']['field_cpage_content']['field'] = 'field_cpage_content';
  $handler->display->display_options['fields']['field_cpage_content']['label'] = 'content';
  /* Field: Content: Custom CSS */
  $handler->display->display_options['fields']['field_cpage_custom_css']['id'] = 'field_cpage_custom_css';
  $handler->display->display_options['fields']['field_cpage_custom_css']['table'] = 'field_data_field_cpage_custom_css';
  $handler->display->display_options['fields']['field_cpage_custom_css']['field'] = 'field_cpage_custom_css';
  $handler->display->display_options['fields']['field_cpage_custom_css']['label'] = 'css_custom';
  /* Field: Content: Stylesheet Includes */
  $handler->display->display_options['fields']['field_cpage_includes_css']['id'] = 'field_cpage_includes_css';
  $handler->display->display_options['fields']['field_cpage_includes_css']['table'] = 'field_data_field_cpage_includes_css';
  $handler->display->display_options['fields']['field_cpage_includes_css']['field'] = 'field_cpage_includes_css';
  $handler->display->display_options['fields']['field_cpage_includes_css']['label'] = 'css_includes';
  $handler->display->display_options['fields']['field_cpage_includes_css']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_cpage_includes_css']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_cpage_includes_css']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_cpage_includes_css']['separator'] = ',';
  /* Field: Content: Custom Javascript */
  $handler->display->display_options['fields']['field_cpage_custom_js']['id'] = 'field_cpage_custom_js';
  $handler->display->display_options['fields']['field_cpage_custom_js']['table'] = 'field_data_field_cpage_custom_js';
  $handler->display->display_options['fields']['field_cpage_custom_js']['field'] = 'field_cpage_custom_js';
  $handler->display->display_options['fields']['field_cpage_custom_js']['label'] = 'js_custom';
  /* Field: Content: Javascript Includes */
  $handler->display->display_options['fields']['field_cpage_includes_js']['id'] = 'field_cpage_includes_js';
  $handler->display->display_options['fields']['field_cpage_includes_js']['table'] = 'field_data_field_cpage_includes_js';
  $handler->display->display_options['fields']['field_cpage_includes_js']['field'] = 'field_cpage_includes_js';
  $handler->display->display_options['fields']['field_cpage_includes_js']['label'] = 'js_includes';
  $handler->display->display_options['fields']['field_cpage_includes_js']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_cpage_includes_js']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_cpage_includes_js']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_cpage_includes_js']['separator'] = ',';
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
    'view_mode' => 'default',
    'links' => 1,
  );
  $handler->display->display_options['fields']['field_catalyst_shared_files']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_catalyst_shared_files']['separator'] = ',';
  /* Field: Content: Blocks */
  $handler->display->display_options['fields']['field_cpage_blocks']['id'] = 'field_cpage_blocks';
  $handler->display->display_options['fields']['field_cpage_blocks']['table'] = 'field_data_field_cpage_blocks';
  $handler->display->display_options['fields']['field_cpage_blocks']['field'] = 'field_cpage_blocks';
  $handler->display->display_options['fields']['field_cpage_blocks']['label'] = 'block_placements';
  $handler->display->display_options['fields']['field_cpage_blocks']['click_sort_column'] = 'block_id';
  $handler->display->display_options['fields']['field_cpage_blocks']['delta_offset'] = '0';
  /* Field: Content: Add Blocks */
  $handler->display->display_options['fields']['field_cpage_blocks_add']['id'] = 'field_cpage_blocks_add';
  $handler->display->display_options['fields']['field_cpage_blocks_add']['table'] = 'field_data_field_cpage_blocks_add';
  $handler->display->display_options['fields']['field_cpage_blocks_add']['field'] = 'field_cpage_blocks_add';
  $handler->display->display_options['fields']['field_cpage_blocks_add']['label'] = 'blocks_ref';
  $handler->display->display_options['fields']['field_cpage_blocks_add']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_cpage_blocks_add']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_cpage_blocks_add']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_cpage_blocks_add']['separator'] = ',';
  /* Field: Content: Custom Head */
  $handler->display->display_options['fields']['field_cpage_head']['id'] = 'field_cpage_head';
  $handler->display->display_options['fields']['field_cpage_head']['table'] = 'field_data_field_cpage_head';
  $handler->display->display_options['fields']['field_cpage_head']['field'] = 'field_cpage_head';
  $handler->display->display_options['fields']['field_cpage_head']['label'] = 'html_head';
  /* Field: Content: Preprocessing */
  $handler->display->display_options['fields']['field_cpage_preprocess']['id'] = 'field_cpage_preprocess';
  $handler->display->display_options['fields']['field_cpage_preprocess']['table'] = 'field_data_field_cpage_preprocess';
  $handler->display->display_options['fields']['field_cpage_preprocess']['field'] = 'field_cpage_preprocess';
  $handler->display->display_options['fields']['field_cpage_preprocess']['label'] = 'preprocess_php';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: IDs */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['ui_name'] = 'IDs';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['nid']['default_argument_options']['code'] = 'return isset($_REQUEST[\'ids\']) ? $_REQUEST[\'ids\'] : NULL;';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['fail'] = 'ignore';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'cpage' => 'cpage',
  );
  $handler->display->display_options['path'] = 'admin/content/cpage/export.xml';
  $export['catalyst_cpage_admin'] = $view;

  return $export;
}
