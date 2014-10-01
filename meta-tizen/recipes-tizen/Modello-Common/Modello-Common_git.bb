require Modello-Common.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Common;tag=041ba94b7af96af4959ce53782191aad45a5e3d0;nobranch=1"

BBCLASSEXTEND += " native "

