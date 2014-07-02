require recipes-image/images/tizen-common-core-image-minimal.bb

SUMMARY = "A Wayland image with a terminal and crosswalk"

LICENSE = "MIT"

DESCRIPTION = "A weston image with Tizen common ."

IMAGE_INSTALL += "crosswalk"
#IMAGE_INSTALL += "tizen-extensions-crosswalk"
IMAGE_INSTALL += "tzdata"

IMAGE_INSTALL += "ttf-dejavu-common"
IMAGE_INSTALL += "ttf-dejavu-sans"
IMAGE_INSTALL += "ttf-dejavu-sans-condensed"
IMAGE_INSTALL += "ttf-dejavu-sans-mono"
IMAGE_INSTALL += "ttf-dejavu-serif"
IMAGE_INSTALL += "ttf-dejavu-serif-condensed"

# Pango modules
IMAGE_INSTALL += "pango-module-basic-fc"
IMAGE_INSTALL += "pango-module-arabic-lang"
IMAGE_INSTALL += "pango-module-indic-lang"