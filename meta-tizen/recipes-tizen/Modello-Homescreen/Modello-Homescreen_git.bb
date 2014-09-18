require Modello-Homescreen.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Homescreen;tag=6c2d6e8b2dfb5a004d2b15a83d7af54b32e4aa74;nobranch=1"

BBCLASSEXTEND += " native "

