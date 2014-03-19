require wrt-widgets.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/test/generic/wrt-widgets;protocol=ssh;tag=d8b7c87535d5fa3df7a4c1c4ed0823423a0487b8;nobranch=1"

