require gdk-pixbuf.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gdk-pixbuf;protocol=ssh;tag=aa91bf36c120e8b9d53a220584d3958b756d810e;nobranch=1"

