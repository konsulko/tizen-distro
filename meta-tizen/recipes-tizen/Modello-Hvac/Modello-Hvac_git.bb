require Modello-Hvac.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Hvac;tag=25355b75ba877b485ef874267d56bb1248f00b53;nobranch=1"

BBCLASSEXTEND += " native "

