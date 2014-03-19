require nasm.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/nasm;protocol=ssh;tag=490bc1f2304f0b39583d2fccf798a22eb8ed10cc;nobranch=1"

