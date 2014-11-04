require Modello-Common.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Common;tag=77a9a6ba5ebe588f6a7e30f6799dcadadcfd162b;nobranch=1"

BBCLASSEXTEND += " native "

