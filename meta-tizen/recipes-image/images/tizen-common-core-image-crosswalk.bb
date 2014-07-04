require recipes-image/images/tizen-common-core-image-minimal.bb

SUMMARY = "A Wayland image with a terminal and crosswalk"

LICENSE = "MIT"

DESCRIPTION = "A weston image with Tizen common ."

CORE_IMAGE_EXTRA_INSTALL += "crosswalk"
#CORE_IMAGE_EXTRA_INSTALL += "tizen-extensions-crosswalk"
CORE_IMAGE_EXTRA_INSTALL += "tzdata"

CORE_IMAGE_EXTRA_INSTALL += "ttf-dejavu-common"
CORE_IMAGE_EXTRA_INSTALL += "ttf-dejavu-sans"
CORE_IMAGE_EXTRA_INSTALL += "ttf-dejavu-sans-condensed"
CORE_IMAGE_EXTRA_INSTALL += "ttf-dejavu-sans-mono"
CORE_IMAGE_EXTRA_INSTALL += "ttf-dejavu-serif"
CORE_IMAGE_EXTRA_INSTALL += "ttf-dejavu-serif-condensed"

# Pango modules
CORE_IMAGE_EXTRA_INSTALL += "pango-module-basic-fc"
CORE_IMAGE_EXTRA_INSTALL += "pango-module-arabic-lang"
CORE_IMAGE_EXTRA_INSTALL += "pango-module-indic-lang"