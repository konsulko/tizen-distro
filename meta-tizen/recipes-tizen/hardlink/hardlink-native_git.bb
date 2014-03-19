require hardlink.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/hardlink;protocol=ssh;tag=c2f4fbf2d17d9b2467ae1d015505490c3df92d3d;nobranch=1"

