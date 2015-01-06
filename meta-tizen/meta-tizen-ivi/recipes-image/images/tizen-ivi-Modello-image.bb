require recipes-image/images/tizen-ivi-core-image.bb

SUMMARY = "Tizen IVI Modello image"

LICENSE = "MIT"

DESCRIPTION = "A Tizen IVI image based on Tizen ivi with Modello ."


# Modello packages
CORE_IMAGE_EXTRA_INSTALL += "packagegroup-tizen-ivi-modello"

# Crosswalk
CORE_IMAGE_EXTRA_INSTALL += "packagegroup-tizen-crosswalk"