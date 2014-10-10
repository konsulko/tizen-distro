require Modello-Multimediaplayer.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Multimediaplayer;tag=d99987ed6c067e188fa3ac715683efe90dbc1581;nobranch=1"

BBCLASSEXTEND += " native "

