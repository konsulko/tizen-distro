require xorg-launch-helper.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/xorg-launch-helper;protocol=ssh;tag=cbac26748e50e17db5c640e019aab4aa35ddabbd;nobranch=1"

