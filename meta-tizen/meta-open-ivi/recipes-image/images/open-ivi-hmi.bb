require recipes-image/images/open-ivi-core.bb

SUMMARY = "A Wayland image with a terminal and crosswalk for Freescale i.MX6"

LICENSE = "MIT"

DESCRIPTION = "Open IVI based on Tizen:Common, GENIVI Media Manager and Automotive Grade Linux application suite."

# open soruce HMI applications based on the AGL app suite
CORE_IMAGE_EXTRA_INSTALL += "packagegroups-hmi-apps"
