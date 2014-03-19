require mkfontdir.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/mkfontdir;protocol=ssh;tag=5e93b821fa2cbf208952a883b1587d1265276fd9;nobranch=1"

