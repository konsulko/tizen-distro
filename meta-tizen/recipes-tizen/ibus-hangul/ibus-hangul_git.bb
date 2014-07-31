require ibus-hangul.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/ibus-hangul;tag=3c6cd6caff440119e04149fe50d67835daa76a7c;nobranch=1"

BBCLASSEXTEND += " native "

