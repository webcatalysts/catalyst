(function($) {

function aceID(fieldId) {
  return fieldId + '-ace';
}

Drupal.wysiwyg.editor.attach.ace = function(context, params, settings) {
  var $textarea = $('#' + params.field);
  $textarea.parent().prepend('<pre id="' + aceID(params.field) + '"></pre>');
  $textarea.hide();

  var editor = ace.edit(aceID(params.field));

  settings.fontsize = 12;
  editor.setFontSize(settings.fontsize + 'px');
  editor.setValue($textarea.val());
  editor.gotoLine(0,0);
  // This is causing throwing a warning with php mode
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
  var height = 300; 
  var rows;
  // Base the editor height on the rows of the textarea
  if (rows = $textarea.attr('rows')) {
    height = Math.round(parseInt(rows) * (settings.fontsize*1.4));
  }
  $container.css('height', height + 'px');
  $container.css('width', '100%');

  if (settings.resizable) {
    $container.addClass('resizable');
    var staticOffset = null;
    function startDrag(e) {
      staticOffset = $container.height() - e.pageY;
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
return;
  var $wrapper; 
  var $toolbar;
  $container.once('ace-setup', function () {
    $container.wrap('<div class="ace-wrapper"></div>');
    $container.parent().prepend($('<div class="ace-toolbar"></div>'));
  });

  $wrapper = $container.parent();
  $toolbar = $wrapper.find('.ace-toolbar');
  function escapeFullScreen(e) {
    if (e.keyCode == 27) {
      $wrapper.unwrap();
      $(document).unbind('keyup', escapeFullScreen);
      editor.resize();
    }
  }
  $toolbar.append('<a class="aceplugin-full-screen">' + Drupal.t('Full screen') + '</a>')
    .click(function () {
      console.log('click');
      if ($wrapper.parent().hasClass('ace-full-screen')) {
        $wrapper.unwrap();
        $(document).unbind('keyup', escapeFullScreen);
        editor.resize();
      }
      else {
        $wrapper.wrap('<div class="ace-full-screen"></div>');
        editor.resize();
        $(document).bind('keyup', escapeFullScreen);
      }
  });


}

Drupal.wysiwyg.editor.detach.ace = function (context, params, trigger) {
  if ($('#' + aceID(params.field), context).length) {
    ace.edit(aceID(params.field)).renderer.destroy();
    ace.edit(aceID(params.field)).destroy();
    $('#' + aceID(params.field)).parent().find('.aceresize-grippie').remove();
    $('#' + aceID(params.field)).remove();
    $('#' + params.field).show();
  }
}
Drupal.wysiwyg.editor.instance.ace = {
  insert: function (content) {
  },
  setContent: function (content) {
    ace.edit(aceID(this.field)).getSession().setValue(content);
  },
  getContent: function () {
    return ace.edit(aceID(this.field)).getSession().getValue();
  }
}

})(jQuery);
