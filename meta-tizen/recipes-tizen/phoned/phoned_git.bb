require phoned.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/phoned;tag=ba27231c6ce2a674db5be654ae1d4d9bc269e1d8;nobranch=1"

BBCLASSEXTEND += " native "

