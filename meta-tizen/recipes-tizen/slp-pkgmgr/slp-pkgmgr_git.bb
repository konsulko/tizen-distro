require slp-pkgmgr.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/slp-pkgmgr;tag=9a44802501ebfd17fbd908a09cf96e89e926c5ba;nobranch=1"

BBCLASSEXTEND += " native "

