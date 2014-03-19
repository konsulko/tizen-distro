require perl-Test-Pod.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/perl-Test-Pod;protocol=ssh;tag=21d5274c376f968cf8332fe3fd1a58b323e192f0;nobranch=1"

