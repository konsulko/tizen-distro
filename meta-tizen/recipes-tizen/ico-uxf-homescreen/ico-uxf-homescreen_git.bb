require ico-uxf-homescreen.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/ico-uxf-homescreen;tag=9fe1c18f6967ff97d36a818460629a5574deb51a;nobranch=1"

BBCLASSEXTEND += " native "

