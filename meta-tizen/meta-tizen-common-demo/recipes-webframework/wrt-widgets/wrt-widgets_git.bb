require wrt-widgets.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/common/wrt-widgets;tag=b7c5bf1ce8f51ad5ca50ba93e612579b2d451ecd;nobranch=1"

BBCLASSEXTEND += " native "

