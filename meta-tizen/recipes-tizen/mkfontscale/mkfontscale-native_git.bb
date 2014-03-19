require mkfontscale.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/mkfontscale;protocol=ssh;tag=8ca716b0b6d071d255bdd1618da236100430bb16;nobranch=1"

