require usbutils.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/usbutils;protocol=ssh;tag=7ac07c9694904426d6be8ec8c33eadf06e8735d0;nobranch=1"

