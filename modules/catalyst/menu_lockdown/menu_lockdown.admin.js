(function ($) {
  Drupal.behaviors.MenuLockdownAdmin = {
    attach: function(context, settings) {
      if ($form = $('#menu-lockdown-admin-settings-form', context)) {
        $form.find('input[type=radio]').click(function (e) {
          $(this).parents('tr').fadeOut();
          var list = $(this).attr('value');
          $input = $form.find('textarea[name=menu_lockdown_' + list + ']');
          $input.attr('value', $input.attr('value') + "\n" + $(this).attr('--data-path'));
$input.effect("highlight", {}, 3000)
          $input.attr('rows', $input.attr('rows')*1+1);
        });
      }
    }
  }
}(jQuery));
