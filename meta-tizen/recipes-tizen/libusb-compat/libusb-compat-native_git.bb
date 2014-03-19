require libusb-compat.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libusb-compat;protocol=ssh;tag=94264d6c4a28117d8b6c4f4e13eaeeb0c30595a5;nobranch=1"

