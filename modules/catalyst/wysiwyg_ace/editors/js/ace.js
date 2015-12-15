(function($) {

function aceID(fieldId) {
  return fieldId + '-ace';
}

Drupal.wysiwyg.editor.attach.ace = function(context, params, settings) {
  ace.require('ace/ext/language_tools');
  ace.require('ace/ext/elastic_tabstops_lite');

  var $textarea = $('#' + params.field);
  $textarea.parent().prepend('<pre id="' + aceID(params.field) + '"></pre>');
  $textarea.hide();

  var editor = ace.edit(aceID(params.field));

  editor.setValue($textarea.val());
  editor.gotoLine(0,0);
  editor.getSession().setMode('ace/mode/' + settings.mode);

  editor.setTheme('ace/theme/' + settings.theme);

  editor.on('change', function () {
    $textarea.val(editor.session.getValue());
  });

  editor.setKeyboardHandler(settings.keybinding);

  // Code collapsing | Folding
  editor.session.setFoldStyle(settings.fold_widgets);
  editor.setShowFoldWidgets(settings.fold_widgets != 'manual');
  editor.setFadeFoldWidgets(settings.fold_widgets_fade);

  editor.setHighlightActiveLine(settings.hightlight_active_line);
  editor.setShowInvisibles(settings.invisibles);
  editor.setDisplayIndentGuides(settings.indent_guides);

  // Tabs
  editor.session.setTabSize(settings.tab_size);
  editor.session.setUseSoftTabs(settings.tab_soft);
  //editor.setOption('useElasticTabstops', settings.elastic_tabstops); 

  editor.renderer.setShowGutter(settings.gutter);
  editor.renderer.setShowPrintMargin(settings.print_margin);

  // Scrolling
  editor.setOption('hScrollBarAlwaysVisible', settings.hscroll_always);
  editor.setOption('vScrollBarAlwaysVisible', settings.vscroll_always);
  editor.setOption('scrollPastEnd', settings.scroll_past_end);
  editor.setAnimatedScroll(settings.animate_scroll);

  editor.setOption('selectionStyle', settings.selection_style);
  editor.setOption('wrap', settings.wrap);

  // Options not implemented:
  // - Incremental search
  // - Orientation (split screen)
  // - Behaviors?
  // - Snippets
  // - Token Tooltips
  // - Emmet http://docs.emmet.io/
  // - Elastic tabstops (error);

  var $container = $(editor.renderer.getContainerElement());
  $container.css('height', '300px');
  $container.css('width', '100%');

  if (settings.resizable) {
    $container.addClass('resizable');
    var staticOffset = null;
    function startDrag(e) {
      console.log('drag start');
      staticOffset = $container.height() - e.pageY;
      console.log('offset:'+ staticOffset);
      $container.css('opacity', 0.25);
      $(document).mousemove(performDrag).mouseup(endDrag);
    }

    function performDrag(e) {
      $container.height(Math.max(32, staticOffset + e.pageY) + 'px');
      editor.resize();
      return false;
    }

    function endDrag(e) {
      $(document).unbind('mousemove', performDrag).unbind('mouseup', endDrag);
      $container.css('opacity', 1);
    }

    var grippie = $('<div class="aceresize-grippie"></div>').mousedown(startDrag);
    grippie.insertAfter($container);
  }
  editor.resize();
  // AJAX submit support
  $textarea.removeClass('wysiwyg-processed');
  console.log('ace complete:' + params.field);
}
Drupal.wysiwyg.editor.detach.ace = function (context, params, trigger) {
  ace.edit(aceID(params.field)).renderer.destroy();
  ace.edit(aceID(params.field)).destroy();
  $('#' + aceID(params.field)).parent().find('.aceresize-grippie').remove();
  $('#' + aceID(params.field)).remove();
  $('#' + params.field).show();
}
Drupal.wysiwyg.editor.instance.ace = {
  insert: function (content) {
alert('insert');
  },
  setContent: function (content) {
alert('setContent');
    ace.edit(aceID(this.field)).getSession().setValue(content);
  },
  getContent: function () {
    return ace.edit(aceID(this.field)).getSession().getValue();
  }
}

})(jQuery);
