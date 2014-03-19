require libmp4v2.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libmp4v2;protocol=ssh;tag=d9279388ce4345e18ca0e25748c7eddda48d1fc7;nobranch=1"

