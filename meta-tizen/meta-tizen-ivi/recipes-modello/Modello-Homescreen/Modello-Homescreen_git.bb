require Modello-Homescreen.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Homescreen;tag=8d99fbba313a1f625280cdf440f63a505790f886;nobranch=1"

BBCLASSEXTEND += " native "

