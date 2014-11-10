require weekeyboard.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/weekeyboard;tag=6790d9d37b28b0dbd20e9ff0713ff9ec4221efc7;nobranch=1"

BBCLASSEXTEND += " native "

