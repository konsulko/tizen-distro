require pkgmgr.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/slp-pkgmgr;tag=c737cd75d68bfc0c9fd7ac762508223e67b9d5c4;nobranch=1"

BBCLASSEXTEND += " native "

