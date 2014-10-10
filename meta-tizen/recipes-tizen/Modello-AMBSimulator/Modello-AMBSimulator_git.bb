require Modello-AMBSimulator.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_AMBSimulator;tag=d0b0056443ee26c66651340b5b2740b9cc2ef445;nobranch=1"

BBCLASSEXTEND += " native "

