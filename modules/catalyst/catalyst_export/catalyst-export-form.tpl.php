<?php

return drupal_render_children($form);
$right = render($form['options']);
$right .= render($form['attached_files']);
$right .= render($form['actions']);
$left = drupal_render_children($form);
?>
<table id="catalyst-export" style="width: 100%;">
<tr>
<td class="left" style="width: 60%;vertical-align:top;">
  <?php print $left; ?>
</td>
<td class="right" style="width: 40%;vertical-align:top;">
<?php print $right; ?>
</td>
</table>
