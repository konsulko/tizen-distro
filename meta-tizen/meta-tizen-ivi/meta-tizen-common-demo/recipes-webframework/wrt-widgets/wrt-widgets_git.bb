require wrt-widgets.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/common/wrt-widgets;tag=72afa2665266e7d34d0c0177a3ddde4d2e8a3b67;nobranch=1"

BBCLASSEXTEND += " native "

