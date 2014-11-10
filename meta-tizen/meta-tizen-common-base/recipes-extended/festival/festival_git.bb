require festival.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/festival;tag=c9840b58b4d651d6c040f783a9d1bb555e6819a8;nobranch=1"

BBCLASSEXTEND += " native "

