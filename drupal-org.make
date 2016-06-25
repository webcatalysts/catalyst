api = 2
core = 7.x

projects[better_exposed_filters][version] = "3.x"
projects[better_exposed_filters][type] = "module"
projects[better_exposed_filters][subdir] = "contrib"
; Keep secondary exposed form options collapsed with default input
; https://www.drupal.org/node/2647600
projects[better_exposed_filters][patch][] = https://www.drupal.org/files/issues/bef-secondary-default-collapse-2-7x3x.patch

projects[better_formats][version] = "1.0-beta2"
projects[better_formats][type] = "module"
projects[better_formats][subdir] = "contrib"

projects[ctools][version] = "1.9"
projects[ctools][type] = "module"
projects[ctools][subdir] = "contrib"

projects[devel][version] = "1.5"
projects[devel][type] = "module"
projects[devel][subdir] = "contrib"

projects[eck][version] = "2.0-rc8"
projects[eck][type] = "module"
projects[eck][subdir] = "contrib"
; Allow administrative bundle menu items to follow altered admin path
; https://www.drupal.org/node/2647610
projects[eck][patch][] = "https://www.drupal.org/files/issues/eck-entity-custom-admin-path-2647610-2-7x2x.patch"

projects[entity][version] = "1.7"
projects[entity][type] = "module"
projects[entity][subdir] = "contrib"

projects[entityreference][version] = "1.1"
projects[entityreference][type] = "module"
projects[entityreference][subdir] = "contrib"

projects[entityreference_autocreate][version] = "1.1"
projects[entityreference_autocreate][type] = "module"
projects[entityreference_autocreate][subdir] = "contrib"

projects[features][version] = "2.10"
projects[features][type] = "module"
projects[features][subdir] = "contrib"

projects[field_group][version] = "1.5"
projects[field_group][type] = "module"
projects[field_group][subdir] = "contrib"

projects[filefield_paths][version] = "1.0"
projects[filefield_paths][type] = "module"
projects[filefield_paths][subdir] = "contrib"

projects[inline_entity_form][version] = "1.8"
projects[inline_entity_form][type] = "module"
projects[inline_entity_form][subdir] = "contrib"

projects[libraries][version] = "2.3"
projects[libraries][type] = "module"
projects[libraries][subdir] = "contrib"

projects[markdown][version] = "1.2"
projects[markdown][type] = "module"
projects[markdown][subdir] = "contrib"

projects[menu_admin_per_menu][version] = "1.1"
projects[menu_admin_per_menu][type] = "module"
projects[menu_admin_per_menu][subdir] = "contrib"

projects[menu_block][version] = "2.7"
projects[menu_block][type] = "module"
projects[menu_block][subdir] = "contrib"

projects[migrate][version] = "2.8"
projects[migrate][type] = "module"
projects[migrate][subdir] = "contrib"

projects[migrate_extras][version] = "2.5"
projects[migrate_extras][type] = "module"
projects[migrate_extras][subdir] = "contrib"

projects[module_filter][version] = "2.0"
projects[module_filter][type] = "module"
projects[module_filter][subdir] = "contrib"

projects[multiple_node_menu][version] = "1.0-beta2"
projects[multiple_node_menu][type] = "module"
projects[multiple_node_menu][subdir] = "contrib"

projects[navbar][version] = "1.7"
projects[navbar][type] = "module"
projects[navbar][subdir] = "contrib"

projects[override_node_options][version] = "1.13"
projects[override_node_options][type] = "module"
projects[override_node_options][subdir] = "contrib"

projects[pathauto][version] = "1.3"
projects[pathauto][type] = "module"
projects[pathauto][subdir] = "contrib"

projects[responsive_preview][version] = "1.1"
projects[responsive_preview][type] = "module"
projects[responsive_preview][subdir] = "contrib"

projects[select_or_other][version] = "2.22"
projects[select_or_other][type] = "module"
projects[select_or_other][subdir] = "contrib"

projects[shortcutperrole][version] = "1.2"
projects[shortcutperrole][type] = "module"
projects[shortcutperrole][subdir] = "contrib"

projects[strongarm][version] = "2.0"
projects[strongarm][type] = "module"
projects[strongarm][subdir] = "contrib"

projects[token][version] = "1.6"
projects[token][type] = "module"
projects[token][subdir] = "contrib"

projects[transliteration][version] = "3.2"
projects[transliteration][type] = "module"
projects[transliteration][subdir] = "contrib"

projects[views][version] = "3.14"
projects[views][type] = "module"
projects[views][subdir] = "contrib"

projects[views_bulk_operations][version] = "3.3"
projects[views_bulk_operations][type] = "module"
projects[views_bulk_operations][subdir] = "contrib"

projects[views_php][version] = "1.0-alpha3"
projects[views_php][type] = "module"
projects[views_php][subdir] = "contrib"

projects[webform][version] = "4.12"
projects[webform][type] = "module"
projects[webform][subdir] = "contrib"

projects[wysiwyg][version] = "2.x-dev"
projects[wysiwyg][type] = "module"
projects[wysiwyg][subdir] = "contrib"

; Sandbox Projects
projects[better_migrate][type] = "module"
projects[better_migrate][subdir] = "sandbox"
projects[better_migrate][download][type] = "git"
projects[better_migrate][download][branch] = "7.x-1.x"
projects[better_migrate][download][url] = "http://git.drupal.org/sandbox/lee20/2223893.git"
projects[better_migrate][download][revision] = "24afd01"

projects[machine][type] = "module"
projects[machine][subdir] = "sandbox"
projects[machine][download][type] = "git"
projects[machine][download][branch] = "7.x-1.x"
projects[machine][download][url] = "http://git.drupal.org/sandbox/lee20/2642174.git"
projects[machine][download][revision] = "3f55b5b"

projects[wysiwyg_ace][type] = "module"
projects[wysiwyg_ace][subdir] = "sandbox"
projects[wysiwyg_ace][download][type] = "git"
projects[wysiwyg_ace][download][branch] = "7.x-1.x"
projects[wysiwyg_ace][download][url] = "http://git.drupal.org/sandbox/lee20/2642232.git"
projects[wysiwyg_ace][download][revision] = "4c9899b"

; Libraries

libraries[twig][download][type] = "get"
libraries[twig][download][url] = "https://github.com/twigphp/Twig/archive/v1.23.1.zip"

libraries[ace][download][type] = "get"
libraries[ace][download][url] = "https://github.com/ajaxorg/ace-builds/archive/v1.2.2.zip"

libraries[modernizr][download][type] = "get"
libraries[modernizr][download][url] = "https://github.com/Modernizr/Modernizr/archive/v2.7.1.zip"

libraries[backbone][download][type] = "get"
libraries[backbone][download][url] = "https://github.com/jashkenas/backbone/archive/1.1.0.zip"

libraries[underscore][download][type] = "get"
libraries[underscore][download][url] = "https://github.com/jashkenas/underscore/archive/1.5.2.zip"

libraries[ckeditor][download][type] = "get"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.5.6/ckeditor_4.5.6_full.zip"
