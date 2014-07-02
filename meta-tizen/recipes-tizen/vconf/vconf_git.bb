require vconf.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/vconf;tag=4bdcb4fc7a40d576fd478176cab04ebc9fd5406d;nobranch=1"

BBCLASSEXTEND += " native "

