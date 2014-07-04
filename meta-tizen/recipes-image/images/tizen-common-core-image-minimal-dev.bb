require recipes-image/images/tizen-common-core-image-minimal.bb

DESCRIPTION = "A weston image with Tizen common and \
is suitable for development work."

IMAGE_FEATURES += "dev-pkgs tools-debug debug-tweaks ssh-server-openssh"
CORE_IMAGE_EXTRA_INSTALL += "attr"
CORE_IMAGE_EXTRA_INSTALL += "util-linux-agetty"
CORE_IMAGE_EXTRA_INSTALL += "strace"
CORE_IMAGE_EXTRA_INSTALL += "gdb"
CORE_IMAGE_EXTRA_INSTALL += "lsof"
CORE_IMAGE_EXTRA_INSTALL += "screen"
CORE_IMAGE_EXTRA_INSTALL += "ldd"
CORE_IMAGE_EXTRA_INSTALL += "libcap"
CORE_IMAGE_EXTRA_INSTALL += "sudo"
CORE_IMAGE_EXTRA_INSTALL += "connman-client"