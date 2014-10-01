require Modello-Installer.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Installer;tag=2082bbebe3e4641c3d7e2520e2055c40033ffaac;nobranch=1"

BBCLASSEXTEND += " native "

