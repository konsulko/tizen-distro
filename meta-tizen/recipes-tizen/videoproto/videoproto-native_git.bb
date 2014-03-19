require videoproto.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/videoproto;protocol=ssh;tag=bff9526e9310b2f7dabced77071f4f0fdfb2bd9f;nobranch=1"

