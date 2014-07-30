require recipes-image/images/tizen-core-image-minimal.bb

SUMMARY = "A very basic Wayland image with a terminal"

IMAGE_FEATURES += "splash package-management ssh-server-dropbear hwcodecs"

LICENSE = "MIT"

inherit core-image distro_features_check

REQUIRED_DISTRO_FEATURES = "wayland pam"

CORE_IMAGE_BASE_INSTALL += "weston weston-init weston-examples clutter-1.0-examples"

DESCRIPTION = "A weston image with Tizen common."


CORE_IMAGE_BASE_INSTALL +=  "weston-common"
CORE_IMAGE_BASE_INSTALL += "weston-common-tz-launcher"
CORE_IMAGE_BASE_INSTALL += "weston-common-config"
CORE_IMAGE_BASE_INSTALL += "desktop-skin"