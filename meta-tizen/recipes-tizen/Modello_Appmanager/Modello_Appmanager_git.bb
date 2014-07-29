require Modello_Appmanager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Appmanager;tag=c71399cb3f4582ada6a44c8259c50d46205668f3;nobranch=1"

BBCLASSEXTEND += " native "

