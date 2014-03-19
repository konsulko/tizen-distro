require test.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/scm/test;protocol=ssh;tag=1eb3341136b5d623c36d6080367b3a3c0c69e926;nobranch=1"

