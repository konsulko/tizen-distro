require weekeyboard.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/weekeyboard;tag=7fc969eec1b425950e1e7a5bafd3d875c5877e77;nobranch=1"

BBCLASSEXTEND += " native "

