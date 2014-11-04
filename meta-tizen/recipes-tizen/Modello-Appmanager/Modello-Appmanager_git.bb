require Modello-Appmanager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Appmanager;tag=29077649bc00e39417d74a1651f94f54a6868a2d;nobranch=1"

BBCLASSEXTEND += " native "

