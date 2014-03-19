require expat.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/expat;protocol=ssh;tag=98c98e8c26c0b67d5a32bbd3f34d513aa2763049;nobranch=1"

