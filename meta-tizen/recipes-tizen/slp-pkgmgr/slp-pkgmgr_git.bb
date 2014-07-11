require slp-pkgmgr.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/slp-pkgmgr;tag=b206231b293d2030db49ea80aa0fad6ca32618c7;nobranch=1"

BBCLASSEXTEND += " native "

