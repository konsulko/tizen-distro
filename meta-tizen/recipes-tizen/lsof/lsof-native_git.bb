require lsof.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/lsof;protocol=ssh;tag=53a531a071f1d58e5c6a06b1d9459b25546c7ecb;nobranch=1"

