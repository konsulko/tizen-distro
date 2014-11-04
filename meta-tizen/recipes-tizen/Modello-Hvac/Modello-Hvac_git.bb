require Modello-Hvac.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Hvac;tag=af5fbddabc6773cbdd33bf8790808fcec64da485;nobranch=1"

BBCLASSEXTEND += " native "

