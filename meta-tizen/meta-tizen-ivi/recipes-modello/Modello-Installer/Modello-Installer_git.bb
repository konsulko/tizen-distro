require Modello-Installer.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Installer;tag=968a4e677273dec4b01b096c3902774d7a2c1de5;nobranch=1"

BBCLASSEXTEND += " native "

