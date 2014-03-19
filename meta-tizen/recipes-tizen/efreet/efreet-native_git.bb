require efreet.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/efreet;protocol=ssh;tag=89d8152c99df44aa2fd1660de0cd8c5239403dbb;nobranch=1"

