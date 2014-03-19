require lrzsz.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/lrzsz;protocol=ssh;tag=6d3f6f3fbe6d5a0b3191c72c05f1a2707dfd08bb;nobranch=1"

