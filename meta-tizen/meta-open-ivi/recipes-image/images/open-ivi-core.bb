require recipes-image/images/tizen-common-crosswalk-imx6.bb

SUMMARY = "A Wayland image with a terminal and crosswalk for Freescale i.MX6"

LICENSE = "MIT"

DESCRIPTION = "Open IVI based on Tizen:Common, GENIVI Media Manager and Automotive Grade Linux application suite."

# Mobile telephony (GSM/UMTS) application development framework
CORE_IMAGE_EXTRA_INSTALL += " ofono ofono-test "

# GENIVI Media Manager
CORE_IMAGE_EXTRA_INSTALL += "media-manager lightmediascanner rygel rygel-plugin-media-export"
