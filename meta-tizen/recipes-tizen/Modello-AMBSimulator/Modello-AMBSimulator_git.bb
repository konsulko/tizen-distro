require Modello-AMBSimulator.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_AMBSimulator;tag=43f878b5e2e103c4fa8fd169600cc7cd81c761d0;nobranch=1"

BBCLASSEXTEND += " native "

