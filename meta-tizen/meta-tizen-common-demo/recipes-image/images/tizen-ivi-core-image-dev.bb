require recipes-image/images/tizen-ivi-core-image.bb

DESCRIPTION = "A Tizen ivi image base on Tizen common and \
               is suitable for development work."

IMAGE_FEATURES += "dev-pkgs tools-debug debug-tweaks ssh-server-openssh"
CORE_IMAGE_EXTRA_INSTALL += "attr"
CORE_IMAGE_EXTRA_INSTALL += "acl"
CORE_IMAGE_EXTRA_INSTALL += "util-linux-agetty"
CORE_IMAGE_EXTRA_INSTALL += "strace"
CORE_IMAGE_EXTRA_INSTALL += "gdb"
CORE_IMAGE_EXTRA_INSTALL += "lsof"
CORE_IMAGE_EXTRA_INSTALL += "screen"
CORE_IMAGE_EXTRA_INSTALL += "ldd"
CORE_IMAGE_EXTRA_INSTALL += "libcap"
CORE_IMAGE_EXTRA_INSTALL += "sudo"
CORE_IMAGE_EXTRA_INSTALL += "connman-client"
CORE_IMAGE_EXTRA_INSTALL += "git"
CORE_IMAGE_EXTRA_INSTALL += "python-json"
CORE_IMAGE_EXTRA_INSTALL += "dlogutil"
