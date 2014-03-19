require libevent.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libevent;protocol=ssh;tag=b566dbae5a43d99861a93e4c8c7a7356a0fcaea5;nobranch=1"

