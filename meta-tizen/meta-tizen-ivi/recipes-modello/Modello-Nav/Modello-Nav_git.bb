require Modello-Nav.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Nav;tag=807037c188b9bcfeb37badb63bb45ef95fb8f52d;nobranch=1"

BBCLASSEXTEND += " native "

