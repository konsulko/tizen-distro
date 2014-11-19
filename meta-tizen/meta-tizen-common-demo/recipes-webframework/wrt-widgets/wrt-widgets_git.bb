require wrt-widgets.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/common/wrt-widgets;tag=63c2d78d4a3a9e40f9193fc350ac18a62a41b9e9;nobranch=1"

BBCLASSEXTEND += " native "

