require libatasmart.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libatasmart;protocol=ssh;tag=346dfa704bda725ca20e1d79943471e5ac88e028;nobranch=1"

