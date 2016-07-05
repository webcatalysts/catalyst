<div class="clearfix">
  <div class="catalyst-menu-widget-column catalyst-menu-widget-column-menu-type">
    <?php print render($element['type']); ?>
  </div>
  <div class="catalyst-menu-widget-column catalyst-menu-widget-column-menu-options">
    <?php print render($element['title']); ?>
    <?php print render($element['description']); ?>
    <?php print render($element['name']); ?>
    <?php print render($element['weight']); ?>
  </div>
  <div class="catalyst-menu-widget-column catalyst-menu-widget-column-menu-parent">
    <?php print render($element['parent']); ?>
  </div>
</div>
