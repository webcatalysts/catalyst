(function ($) {
  Drupal.behaviors.catalystExportForm = {
    attach: function (context, settings) {
      var previewDialog = $('#catalyst-export-preview-wrapper');
      if (previewDialog.length && previewDialog.html() != "") {
        previewDialog.dialog({
          autoOpen: true,
          modal: true,
          width: 600,
          height: 400,
          resizable: false,
          draggable: false,
        });

      }
    }
  }
}(jQuery));
