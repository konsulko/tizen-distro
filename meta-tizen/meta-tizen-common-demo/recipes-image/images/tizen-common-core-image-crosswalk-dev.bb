require recipes-image/images/tizen-common-core-image-crosswalk.bb

DESCRIPTION = "A weston image with Tizen common and \
is suitable for development work."

IMAGE_FEATURES += "dev-pkgs tools-debug debug-tweaks ssh-server-openssh"
CORE_IMAGE_EXTRA_INSTALL += "packagegroup-tizen-dev-tools"