require recipes-image/images/tizen-common-core-image-minimal.bb

DESCRIPTION = "A weston image with Tizen common and \
is suitable for development work."

IMAGE_FEATURES += "dev-pkgs"
IMAGE_INSTALL += "attr"