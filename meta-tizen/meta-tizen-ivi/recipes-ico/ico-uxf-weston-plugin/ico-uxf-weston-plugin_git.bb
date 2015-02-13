require ico-uxf-weston-plugin.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/ico-uxf-weston-plugin;tag=6ecf3762b6feb381279551ff72202816596046b6;nobranch=1"

BBCLASSEXTEND += " native "

