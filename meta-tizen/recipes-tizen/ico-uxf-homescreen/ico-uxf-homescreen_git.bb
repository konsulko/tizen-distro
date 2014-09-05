require ico-uxf-homescreen.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/ico-uxf-homescreen;tag=bd1720857784580d8f86427aa94b31c9027b7b44;nobranch=1"

BBCLASSEXTEND += " native "

