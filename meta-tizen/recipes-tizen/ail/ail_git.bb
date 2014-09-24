require ail.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/ail;tag=7e3ef0968ba539a3c224c593ffe1d4d47cbc2ac5;nobranch=1"

BBCLASSEXTEND += " native "

