require perl-Devel-Symdump.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/perl-Devel-Symdump;protocol=ssh;tag=97a914b7ae3cbb29947e4fb454581f09ada6d107;nobranch=1"

