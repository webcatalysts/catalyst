(function ($) {
  Drupal.behaviors.catalystAdminViews = {
    attach: function (context, settings) {
      // Move views exposed filters secondary options to the very end
      // to allow submit/reset buttons to appear before
      $('div.view').each( function () {
        var match = $(this).filter(function() {
          return((" " + this.className + " ").match(/view-catalyst/));
        });
        if (match) {
          if ($secondary = $(this).find('.views-widget-filter-secondary')) {
            $parent = $secondary.parent();
            $secondary.detach();
            $parent.append($secondary);
          }
        }
      });
    }
  }
})(jQuery);
