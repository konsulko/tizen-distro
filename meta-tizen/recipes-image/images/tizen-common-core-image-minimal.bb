SUMMARY = "A very basic Wayland image with a terminal"

IMAGE_FEATURES += "splash package-management ssh-server-dropbear hwcodecs"

LICENSE = "MIT"

inherit core-image distro_features_check

REQUIRED_DISTRO_FEATURES = "wayland pam"

CORE_IMAGE_BASE_INSTALL += "weston weston-init weston-examples clutter-1.0-examples"

DESCRIPTION = "A weston image with Tizen common."

DEPENDS += " tar-replacement-native "

CORE_IMAGE_BASE_INSTALL += "connman"
CORE_IMAGE_BASE_INSTALL += "weston-common"
CORE_IMAGE_BASE_INSTALL += "mesa-megadriver"
CORE_IMAGE_BASE_INSTALL += "meta-common"
CORE_IMAGE_BASE_INSTALL += "pam"
CORE_IMAGE_BASE_INSTALL += "weston-common-tz-launcher"
CORE_IMAGE_BASE_INSTALL += "weston-common-config"
CORE_IMAGE_BASE_INSTALL += "user-session-units"
CORE_IMAGE_BASE_INSTALL += "default-ac-domains"
CORE_IMAGE_BASE_INSTALL += "desktop-skin"
CORE_IMAGE_BASE_INSTALL += "rpm-security-plugin"
CORE_IMAGE_EXTRA_INSTALL += "config-image"
CORE_IMAGE_BASE_INSTALL += "kernel-modules"

export SYSROOT = "${IMAGE_ROOTFS}"
