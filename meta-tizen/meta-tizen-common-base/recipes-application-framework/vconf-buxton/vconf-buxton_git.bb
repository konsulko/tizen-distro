require vconf-buxton.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/vconf-buxton;tag=837474017fea13e4c2aa5126666947ff5caa578f;nobranch=1"

BBCLASSEXTEND += " native "

