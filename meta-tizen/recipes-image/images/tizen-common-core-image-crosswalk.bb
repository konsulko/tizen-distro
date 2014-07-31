require recipes-image/images/tizen-common-core-image-minimal.bb

SUMMARY = "A Wayland image with a terminal and crosswalk"

LICENSE = "MIT"

DESCRIPTION = "A weston image with Tizen common ."

# Crosswalk
CORE_IMAGE_EXTRA_INSTALL += "packagegroup-tizen-crosswalk"

# Time zone
CORE_IMAGE_EXTRA_INSTALL += "tzdata"
