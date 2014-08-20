require ico-uxf-homescreen-sample-apps.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/ico-uxf-homescreen-sample-apps;tag=2f4bf10ace3ed6fb66de4651be410ecca0d20b22;nobranch=1"

BBCLASSEXTEND += " native "

