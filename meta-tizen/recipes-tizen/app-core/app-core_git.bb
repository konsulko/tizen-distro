require app-core.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/app-core;tag=b772c8ca27263c3f2d5f23340000bb79081123ec;nobranch=1"

BBCLASSEXTEND += " native "

