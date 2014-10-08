require recipes-image/images/tizen-ivi-core-image.bb

SUMMARY = "Tizen IVI ico image"

LICENSE = "MIT"

DESCRIPTION = "A Tizen IVI image based on Tizen ivi with ico ."


# Modello packages
CORE_IMAGE_EXTRA_INSTALL += "packagegroup-tizen-ivi-ico"

# Crosswalk
CORE_IMAGE_EXTRA_INSTALL += "packagegroup-tizen-crosswalk"