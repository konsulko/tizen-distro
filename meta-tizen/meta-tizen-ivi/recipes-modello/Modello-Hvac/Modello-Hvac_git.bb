require Modello-Hvac.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Hvac;tag=f8a0549c2c4efd2c108f0e3941b7edef88714e2b;nobranch=1"

BBCLASSEXTEND += " native "

