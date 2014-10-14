require murphy.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/murphy;tag=7934858e21456e894778c8ec5da8d1c7f21e7830;nobranch=1"

BBCLASSEXTEND += " native "

