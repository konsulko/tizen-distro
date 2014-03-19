require diffutils.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/diffutils;protocol=ssh;tag=b433c69cd752e68737c15f34c327f1d7e4780d1d;nobranch=1"

