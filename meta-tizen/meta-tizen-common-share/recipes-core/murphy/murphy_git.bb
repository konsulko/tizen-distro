require murphy.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/murphy;tag=ec834e4a57bf4a9ea63554e2bf3b247b666fe347;nobranch=1"

BBCLASSEXTEND += " native "

