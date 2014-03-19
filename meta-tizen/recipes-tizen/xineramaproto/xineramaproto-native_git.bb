require xineramaproto.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/xineramaproto;protocol=ssh;tag=aea15fbe2c5005f500bf632ba3f5a36b6d497f34;nobranch=1"

