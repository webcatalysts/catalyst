(function ($) {
  Drupal.behaviors.layoutDoctypeOnChange = {
    attach: function (context, settings) {
      if (typeof settings.layoutDoctypeOnChange != 'undefined') {
        var callbacks = settings.layoutDoctypeOnChange.callbacks;
        var ele = $(settings.layoutDoctypeOnChange.selector);
        ele.attr('data-val', ele.val()); 
        ele.change(function () {
          var prevVal = ele.attr('data-val');
          var nextVal = ele.val();
          if (typeof callbacks.ondeselect[prevVal] != 'undefined') {
            eval(callbacks.ondeselect[prevVal]);
          }
          if (typeof callbacks.onselect[nextVal] != 'undefined') {
            eval(callbacks.onselect[nextVal]);
          }
          ele.attr('data-val', ele.val()); 
        });
        ele.change();
      }
    }
  }
}(jQuery));
