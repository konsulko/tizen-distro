require Modello-Multimediaplayer.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Multimediaplayer;tag=5ecfa7b305bf2cc842aa8cc242dc153bc5ddc96f;nobranch=1"

BBCLASSEXTEND += " native "

