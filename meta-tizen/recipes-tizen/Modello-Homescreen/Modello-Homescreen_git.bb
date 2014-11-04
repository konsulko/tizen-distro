require Modello-Homescreen.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Homescreen;tag=7aa5723eceb5a35f56dfbd03e4e2ffc2c5f9b742;nobranch=1"

BBCLASSEXTEND += " native "

