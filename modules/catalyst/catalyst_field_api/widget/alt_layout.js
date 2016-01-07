(function ($) {
  Drupal.behaviors.blockPlacementFields = {
    attach: function (context, settings) {
              return;
      var $layoutSelect = $('#edit-field-cpage-layout-und');
      $layoutSelect.once('loadregions', function () {
        function onLayoutChange() {
          var $layoutHidden = $('[id^="' + settings.blockPlacement.layout_id + '"]').first();
          console.log($layoutHidden.val());
          console.log($layoutSelect.val());
          if ($layoutHidden.val() == $layoutSelect.val()) {
            return;
          }
          if ($layoutSelect.val() == '') {
            return;
          }
          console.log($layoutHidden.attr('id'));
          $layoutHidden.children('option').attr('selected', false);
          $layoutHidden.children('option[value="'+$(this).val()+'"]').attr('selected', true);
          //$layoutHidden.mousedown();
          $layoutHidden.trigger('mousedown');
         // $layoutHidden.trigger('loadregions');
          //$layoutHidden.remove();
        }
        $layoutSelect.bind('change', onLayoutChange);
      });
    }
  }
})(jQuery);
