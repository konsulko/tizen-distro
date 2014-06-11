require pkgmgr-info.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/pkgmgr-info;tag=90a380a522758e526c5dfedd2d4d1040bbb00e0f;nobranch=1"

BBCLASSEXTEND += " native "

