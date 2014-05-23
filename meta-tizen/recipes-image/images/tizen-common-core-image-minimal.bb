SUMMARY = "A very basic Wayland image with a terminal"

IMAGE_FEATURES += "splash package-management ssh-server-dropbear hwcodecs"

LICENSE = "MIT"

inherit core-image distro_features_check

REQUIRED_DISTRO_FEATURES = "wayland pam"

CORE_IMAGE_BASE_INSTALL += "weston weston-init weston-examples clutter-1.0-examples"

DESCRIPTION = "A weston image with Tizen common."

DEPENDS += " tar-replacement-native "

IMAGE_INSTALL += "connman"
IMAGE_INSTALL += "weston-common"
IMAGE_INSTALL += "mesa-driver-i965"
IMAGE_INSTALL += "meta"
IMAGE_INSTALL += "libpam"
IMAGE_INSTALL += "weston-common-tz-launcher"
IMAGE_INSTALL += "weston-common-config"

# Doesn't build: needs to be fixed:
#IMAGE_INSTALL += "user-session-units"

#IMAGE_INSTALL += "crosswalk"
