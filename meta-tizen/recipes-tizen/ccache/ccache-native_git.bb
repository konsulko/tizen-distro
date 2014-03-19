require ccache.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/ccache;protocol=ssh;tag=dd0ea6ced9cdb09a6e17c1216ac650c3440e38e2;nobranch=1"

