require vconf.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/vconf;tag=4743f153c4f30c05e65c895ee03b689fafa29a43;nobranch=1"

BBCLASSEXTEND += " native "

