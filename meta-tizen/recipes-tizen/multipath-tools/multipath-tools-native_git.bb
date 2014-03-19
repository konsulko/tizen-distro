require multipath-tools.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/multipath-tools;protocol=ssh;tag=cc098a1bc7751211548071606f201f3a5e68301a;nobranch=1"

