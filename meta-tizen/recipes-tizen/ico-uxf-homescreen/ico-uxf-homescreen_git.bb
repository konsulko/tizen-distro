require ico-uxf-homescreen.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/ico-uxf-homescreen;tag=74dc27c5bac25a80ad7374515fd043f4ae4bd12f;nobranch=1"

BBCLASSEXTEND += " native "

