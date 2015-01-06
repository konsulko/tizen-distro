SUMMARY = "A very basic Wayland image with a terminal"

IMAGE_FEATURES += "splash package-management ssh-server-dropbear hwcodecs"

LICENSE = "MIT"

inherit core-image distro_features_check

REQUIRED_DISTRO_FEATURES = "wayland pam"

CORE_IMAGE_BASE_INSTALL += "weston weston-init clutter-1.0-examples"

DESCRIPTION = "A weston image with Tizen common."

DEPENDS += " tar-replacement-native "

CORE_IMAGE_BASE_INSTALL += "connman"
CORE_IMAGE_BASE_INSTALL += "${WESTONSTARTUP}"

# Profile specific configuration - default is Tizen common
CORE_IMAGE_BASE_INSTALL += "${IMAGECONFIG}"

CORE_IMAGE_BASE_INSTALL += "tlm"
CORE_IMAGE_BASE_INSTALL += "${TLMCONFIG}"


CORE_IMAGE_BASE_INSTALL += "mesa-megadriver"
CORE_IMAGE_BASE_INSTALL += "libegl-gallium"
CORE_IMAGE_BASE_INSTALL += "libegl-mesa"
CORE_IMAGE_BASE_INSTALL += "libgbm"
CORE_IMAGE_BASE_INSTALL += "libgbm-gallium"
CORE_IMAGE_BASE_INSTALL += "mesa-driver-pipe-swrast"
CORE_IMAGE_BASE_INSTALL += "mesa-driver-pipe-vmwgfx"
CORE_IMAGE_BASE_INSTALL += "mesa-driver-pipe-i915"
CORE_IMAGE_BASE_INSTALL += "libgles1-mesa"
CORE_IMAGE_BASE_INSTALL += "libgles2-mesa"
CORE_IMAGE_BASE_INSTALL += "gum-utils"
CORE_IMAGE_BASE_INSTALL += "meta-common"
CORE_IMAGE_BASE_INSTALL += "pam"
CORE_IMAGE_BASE_INSTALL += "user-session-units"
CORE_IMAGE_BASE_INSTALL += "default-ac-domains"
CORE_IMAGE_BASE_INSTALL += "rpm-security-plugin"
CORE_IMAGE_BASE_INSTALL += "config-image"
CORE_IMAGE_BASE_INSTALL += "kernel-modules"
CORE_IMAGE_BASE_INSTALL += "less"
CORE_IMAGE_BASE_INSTALL += "bash"
CORE_IMAGE_BASE_INSTALL += "psmisc"
CORE_IMAGE_BASE_INSTALL += "coreutils"
CORE_IMAGE_BASE_INSTALL += "procps"

# Fonts
CORE_IMAGE_EXTRA_INSTALL += "packagegroup-tizen-fonts-ttf"
CORE_IMAGE_EXTRA_INSTALL += "packagegroup-tizen-fonts-pango"

export SYSROOT = "${IMAGE_ROOTFS}"
