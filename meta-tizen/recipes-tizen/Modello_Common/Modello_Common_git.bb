require Modello_Common.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Common;tag=fee0b7fd0e2792f8d0ec972018f0b57c26aaedd0;nobranch=1"

BBCLASSEXTEND += " native "

