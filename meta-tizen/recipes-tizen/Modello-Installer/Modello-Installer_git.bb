require Modello-Installer.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Installer;tag=fff8ba176aee88d755e2bc363c05b6b4945cdddb;nobranch=1"

BBCLASSEXTEND += " native "

