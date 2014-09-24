require Modello-Appmanager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Appmanager;tag=96f0d6c497101b90ee5a0c91786a0cf5af88d7a0;nobranch=1"

BBCLASSEXTEND += " native "

