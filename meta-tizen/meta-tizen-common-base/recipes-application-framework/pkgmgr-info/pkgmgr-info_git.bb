require pkgmgr-info.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/pkgmgr-info;tag=81ec3ec48b6a7f8823a861bd640a6e65b5f3bb90;nobranch=1"

BBCLASSEXTEND += " native "

