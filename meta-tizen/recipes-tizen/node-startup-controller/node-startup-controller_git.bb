require node-startup-controller.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/node-startup-controller;tag=d269ec968e6723a101d346e9843bbfe5ae15238c;nobranch=1"

BBCLASSEXTEND += " native "

