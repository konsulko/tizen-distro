require ico-uxf-weston-plugin.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/ico-uxf-weston-plugin;tag=240f812897b4191589ae87e3d8bc45b7117e5026;nobranch=1"

BBCLASSEXTEND += " native "

