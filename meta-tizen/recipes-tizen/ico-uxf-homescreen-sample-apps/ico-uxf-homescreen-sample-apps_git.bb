require ico-uxf-homescreen-sample-apps.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/ico-uxf-homescreen-sample-apps;tag=b6b8af930dc8db218d9081c5be0e45dab00fe1b9;nobranch=1"

BBCLASSEXTEND += " native "

