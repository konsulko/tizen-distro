DESCRIPTION = "A small image just capable of allowing a device to boot."

IMAGE_INSTALL = ""
IMAGE_INSTALL += "${ROOTFS_PKGMANAGE_BOOTSTRAP}"
IMAGE_INSTALL += "packagegroup-tizen-Base-System"
IMAGE_INSTALL += "packagegroup-tizen-Generic-Middleware"
IMAGE_INSTALL += "packagegroup-tizen-Wayland"
IMAGE_INSTALL += "packagegroup-tizen-Console-Tools"
IMAGE_INSTALL += "packagegroup-tizen-Generic-Adaptation"
IMAGE_INSTALL += "packagegroup-tizen-Generic-Applications"
IMAGE_INSTALL += "packagegroup-tizen-Generic-Packaging"


IMAGE_LINGUAS = " "

LICENSE = "MIT"

#inherit core-image

IMAGE_ROOTFS_SIZE = "8192"

#Need to be tested.
#PREFERRED_PROVIDER_virtual/kernel ?= "kernel-x86-ivi"

# remove not needed ipkg informations
#ROOTFS_POSTPROCESS_COMMAND += "remove_packaging_data_files ; "

LIC_FILES_CHKSUM = "file://${COREBASE}/LICENSE;md5=3f40d7994397109285ec7b81fdeb3b58 \
                    file://${COREBASE}/meta/COPYING.MIT;md5=3da9cfbcb788c80a0384361b4de20420"

PACKAGE_GROUP_tizen = "packagegroup-tizen-core packagegroup-tizen-commonwayland-core"




inherit image


ROOTFS_POSTPROCESS_COMMAND += "rootfs_postscript"