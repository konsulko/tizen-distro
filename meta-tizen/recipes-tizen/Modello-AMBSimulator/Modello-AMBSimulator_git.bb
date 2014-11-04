require Modello-AMBSimulator.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_AMBSimulator;tag=6dcac734d95f99d36b8b5bab9799b3f8860bb176;nobranch=1"

BBCLASSEXTEND += " native "

