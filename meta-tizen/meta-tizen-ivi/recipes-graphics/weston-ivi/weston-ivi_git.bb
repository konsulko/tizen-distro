require weston-ivi.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/weston-ivi;tag=e1c5b89c0a00d8910549a1d4cc371ec1ce6d0284;nobranch=1"

BBCLASSEXTEND += " native "

