require evas.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/evas;protocol=ssh;tag=249fccf3d182c88b025d60d5d0a9a66fae0e8b7e;nobranch=1"

