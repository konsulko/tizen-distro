require Modello-AMBSimulator.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_AMBSimulator;tag=497607ee297d9e2098edc8ac2483355c35ca473e;nobranch=1"

BBCLASSEXTEND += " native "

