require adns.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/adns;protocol=ssh;tag=b17c61b0cea0a7b65f33a8454c0a017b5f95124c;nobranch=1"

