require rpmorphan.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/rpmorphan;protocol=ssh;tag=901aa7f38cb8841312a4d9f4752a235d31d01850;nobranch=1"

