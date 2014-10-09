require wrt-widgets.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/common/wrt-widgets;tag=e84337cd05c5879886ab5a87ef68c500d64cbab7;nobranch=1"

BBCLASSEXTEND += " native "

