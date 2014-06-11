require app-checker.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/app-checker;tag=a75f4df722d764c4e2d337d09b8a985a8bba47a2;nobranch=1"

BBCLASSEXTEND += " native "

