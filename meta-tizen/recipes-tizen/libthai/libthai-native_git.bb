require libthai.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libthai;protocol=ssh;tag=56b986b5c0fa3c3f2c0bb07139953d27a283ef8c;nobranch=1"

