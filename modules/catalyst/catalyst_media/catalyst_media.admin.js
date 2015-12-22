(function ($) {
  Drupal.behaviors.catalystMediaAdmin = {
    attach: function (context, settings) {
      var ids = settings.catalystMediaAdmin.ids;
      var $typeField = $('#' + ids.type + ' select')
      $typeField.change(function () {
        switch ($(this).val()) {
          case 'local':
          case 'remote':
            $('#' + ids.path).show();
            $('#' + ids.custom).hide();
            break;
          default:
          case 'custom':
            $('#' + ids.custom).show();
            $('#' + ids.path).hide();
            break;
        }
      });
      $typeField.change();
    }
  }
})(jQuery);
