require Modello-Phone.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Phone;tag=4eb3acbbb8423fa5ea06e7576def8bc6cb3ab67a;nobranch=1"

BBCLASSEXTEND += " native "

