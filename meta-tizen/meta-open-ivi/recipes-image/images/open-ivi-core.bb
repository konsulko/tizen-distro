require recipes-image/images/tizen-common-crosswalk-imx6.bb

SUMMARY = "A Wayland image with a terminal and crosswalk for Freescale i.MX6"

LICENSE = "MIT"

DESCRIPTION = "Open IVI based on Tizen:Common, GENIVI Media Manager and Automotive Grade Linux application suite."

require recipes-image/images/open-ivi-minimal.inc

# GENIVI Media Manager
CORE_IMAGE_EXTRA_INSTALL += "\
			media-manager \
			lightmediascanner \
			lightmediascanner-meta \
			rygel \
			rygel-plugin-media-export \
			rygel-plugin-lms \
			dleyna-core \
			dleyna-connector-dbus \
			dleyna-server\
			dleyna-renderer \
                        media-manager-extension \
			"
