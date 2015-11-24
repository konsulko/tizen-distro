require recipes-image/images/tizen-common-crosswalk-imx6.bb

SUMMARY = "A Wayland image with a terminal and crosswalk for Freescale i.MX6"

LICENSE = "MIT"

DESCRIPTION = "Open IVI based on Tizen:Common, GENIVI Media Manager and Automotive Grade Linux application suite."

# Mobile telephony (GSM/UMTS) application development framework
CORE_IMAGE_EXTRA_INSTALL += " ofono ofono-test "

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

# gstreamer
CORE_IMAGE_EXTRA_INSTALL += "\
			gstreamer1.0 \
			gstreamer1.0-plugins-imx-meta \
			gstreamer1.0-plugins-base-meta \
			gstreamer1.0-plugins-good-meta \
			gstreamer1.0-plugins-bad-meta \
			gstreamer1.0-plugins-ugly-meta \
			gstreamer1.0-plugins-good \
			gstreamer1.0-plugins-bad \
			gstreamer1.0-plugins-ugly \
			gstreamer1.0-libav  \
			gstreamer1.0-plugins-imx \
			alsa-utils \
			gst-fsl-plugin \
			gstreamer1.0-meta-base \
			gstreamer1.0-meta-video \
			gstreamer1.0-meta-audio \
			gstreamer1.0-meta-debug \
			"

# Test plan
CORE_IMAGE_EXTRA_INSTALL += "packagegroup-test-plan"
