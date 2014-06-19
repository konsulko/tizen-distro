require slp-pkgmgr.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/slp-pkgmgr;tag=1a19052d22ef1cc8dc5cc4ccada4cfa649735f78;nobranch=1"

BBCLASSEXTEND += " native "

