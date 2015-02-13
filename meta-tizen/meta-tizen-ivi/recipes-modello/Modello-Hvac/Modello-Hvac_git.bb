require Modello-Hvac.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Hvac;tag=0b4d10a69cd68e4457bf6f19feeaa4004f528a7d;nobranch=1"

BBCLASSEXTEND += " native "

