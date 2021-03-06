# Mobile telephony (GSM/UMTS) application development framework
CORE_IMAGE_EXTRA_INSTALL += " ofono ofono-test "

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

#pulseaudio
CORE_IMAGE_EXTRA_INSTALL += "\
			pulseaudio \
			pulseaudio-config \
			pulseaudio-module-augment-properties \
			pulseaudio-module-bluetooth \
			pulseaudio-module-combine-sink \
			pulseaudio-module-dbus-protocol \
			pulseaudio-module-dev \
			pulseaudio-module-filter \
			pulseaudio-module-null-source \
			pulseaudio-module-raop \
			pulseaudio-module-switch-on-connect \
			pulseaudio-utils \
			pulseaudio-vala-bindings \
			"

# Test plan
CORE_IMAGE_EXTRA_INSTALL += "packagegroup-test-plan"

# Michelle 2 Plus support
CORE_IMAGE_EXTRA_INSTALL += "packagegroup-michelle2p"
