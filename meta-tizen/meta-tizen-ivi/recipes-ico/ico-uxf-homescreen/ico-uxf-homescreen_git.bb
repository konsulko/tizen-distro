require ico-uxf-homescreen.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/ico-uxf-homescreen;tag=f9c2b84da9b97d6d1f49e2e11ed41c8d96354ce4;nobranch=1"

BBCLASSEXTEND += " native "

