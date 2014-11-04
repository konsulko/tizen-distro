require ico-uxf-weston-plugin.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/ico-uxf-weston-plugin;tag=8ccf810f079b757e6be43f4c0ec2107351776b13;nobranch=1"

BBCLASSEXTEND += " native "

