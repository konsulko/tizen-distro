require Modello-Multimediaplayer.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Multimediaplayer;tag=e2f2f8c061d4910a6f17fd6b9d24376791dbcd33;nobranch=1"

BBCLASSEXTEND += " native "

