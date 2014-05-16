require slp-pkgmgr.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/slp-pkgmgr;tag=9f13493a8a45a9eb1d7ed15a5f4e5f35243e70e7;nobranch=1"

BBCLASSEXTEND += " native "

