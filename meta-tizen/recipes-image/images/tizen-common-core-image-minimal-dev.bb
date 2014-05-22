require recipes-image/images/tizen-common-core-image-minimal.bb

DESCRIPTION = "A weston image with Tizen common and \
is suitable for development work."

IMAGE_FEATURES += "dev-pkgs tools-debug debug-tweaks ssh-server-openssh"
IMAGE_INSTALL += "attr"
IMAGE_INSTALL += "util-linux-agetty"
IMAGE_INSTALL += "strace"
IMAGE_INSTALL += "gdb"