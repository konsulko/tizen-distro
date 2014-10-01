require Modello-Homescreen.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Homescreen;tag=56c5aece6343a5fe5ad53af4aa39ce681c48f15e;nobranch=1"

BBCLASSEXTEND += " native "

