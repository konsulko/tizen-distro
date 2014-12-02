require status.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/status;tag=bebaf1fd70a6b15dbb428f223e75811a83ece711;nobranch=1"

BBCLASSEXTEND += " native "

