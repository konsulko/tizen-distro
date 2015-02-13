require ico-vic-amb-plugin.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/ico-vic-amb-plugin;tag=2add0179587f8c9bf8e6e5ac976a52ab70aa9374;nobranch=1"

BBCLASSEXTEND += " native "

