require perl-TimeDate.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/perl-TimeDate;protocol=ssh;tag=3727d57bb7aa46b7b363691a3f406bb274a78bba;nobranch=1"

