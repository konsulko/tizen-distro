require app-checker.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/app-checker;protocol=ssh;tag=c69c0e37b6aa9c24b2aa4e99e37319870a21508c;nobranch=1"

