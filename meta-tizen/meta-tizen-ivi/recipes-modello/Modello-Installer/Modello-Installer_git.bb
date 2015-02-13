require Modello-Installer.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Installer;tag=467ba2a8730e3a116ca7c726df88a8759f6238be;nobranch=1"

BBCLASSEXTEND += " native "

