require recipes-image/images/tizen-common-core-image-minimal.bb

SUMMARY = "A Wayland image with a terminal and crosswalk"

LICENSE = "MIT"

DESCRIPTION = "A weston image with Tizen common ."

CORE_IMAGE_EXTRA_INSTALL += "crosswalk"
#CORE_IMAGE_EXTRA_INSTALL += "tizen-extensions-crosswalk"
CORE_IMAGE_EXTRA_INSTALL += "tzdata"
