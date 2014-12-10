require Modello-Common.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Common;tag=edf93cb2d0ece3403e01537aef064f5172025dc4;nobranch=1"

BBCLASSEXTEND += " native "

