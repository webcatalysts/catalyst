<?php

$right = render($form['options']);
$right .= render($form['attached_files']);
$right .= render($form['actions']);
$left = drupal_render_children($form);
?>
<table style="width: 100%;">
<tr>
<td style="width: 50%;vertical-align:top;">
<?php print $left; ?>
</td>
<td style="width: 50%;vertical-align:top;">
<?php print $right; ?>
</td>
</table>
