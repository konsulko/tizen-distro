require pkgmgr-info.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/pkgmgr-info;tag=ea3c01c9cf3c3fa47de3598fcb17c6cf8f56adcb;nobranch=1"

BBCLASSEXTEND += " native "

