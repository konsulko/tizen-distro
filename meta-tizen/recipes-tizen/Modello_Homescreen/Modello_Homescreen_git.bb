require Modello_Homescreen.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Homescreen;tag=4becb3c675da8f5dd5fd7c3c03e404abf86a3028;nobranch=1"

BBCLASSEXTEND += " native "

