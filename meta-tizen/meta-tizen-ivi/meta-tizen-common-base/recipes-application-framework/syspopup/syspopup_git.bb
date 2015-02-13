require syspopup.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/base/syspopup;tag=613e33a194a4c5f8eeb1022073e73248afcf6c77;nobranch=1"

BBCLASSEXTEND += " native "

