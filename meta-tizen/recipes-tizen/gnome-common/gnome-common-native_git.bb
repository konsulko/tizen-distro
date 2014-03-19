require gnome-common.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gnome-common;protocol=ssh;tag=a3988cb22c3494014516ca9b4cacb8ee3eb03b11;nobranch=1"

