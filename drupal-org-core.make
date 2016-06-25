api = 2
core = 7.x
projects[drupal][type] = core
projects[drupal][version] = 7.44


; Registry rebuild should not parse the same file twice in the same request
; http://drupal.org/node/1470656
projects[drupal][patch][] = "http://drupal.org/files/drupal-1470656-14.patch"
