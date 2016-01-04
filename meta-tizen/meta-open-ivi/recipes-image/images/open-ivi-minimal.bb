require recipes-image/images/tizen-common-imx6.bb

SUMMARY = "A Wayland image with a terminal for Freescale i.MX6"

LICENSE = "MIT"

DESCRIPTION = "Open IVI based on Tizen:Common without Crosswalk"

# Time zone
CORE_IMAGE_EXTRA_INSTALL += "tzdata"

require recipes-image/images/open-ivi-minimal.inc
