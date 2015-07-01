require recipes-image/images/tizen-common-crosswalk-imx6.bb

SUMMARY = "A Wayland image with a terminal and crosswalk for Freescale i.MX6"

LICENSE = "MIT"

DESCRIPTION = "Open IVI based on Tizen:Common, GENIVI Media Manager and Automotive Grade Linux application suite."

# GENIVI Media Manager
CORE_IMAGE_EXTRA_INSTALL += "media-manager lightmediascanner gupnp-av-dev gssdp gupnp libgee gupnp-av-dev"
