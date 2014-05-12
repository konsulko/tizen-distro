require app-checker.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/app-checker;tag=c69c0e37b6aa9c24b2aa4e99e37319870a21508c;nobranch=1"

BBCLASSEXTEND = "native"

