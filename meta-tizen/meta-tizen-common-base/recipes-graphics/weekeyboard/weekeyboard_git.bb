require weekeyboard.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/weekeyboard;tag=a449542772a9cced01357c51c67613399a9b5649;nobranch=1"

BBCLASSEXTEND += " native "

