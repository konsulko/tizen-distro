require lemolo.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/lemolo;tag=4d73c5d50328dffb0769f7627cdb8cb21ab2f01a;nobranch=1"

BBCLASSEXTEND += " native "

