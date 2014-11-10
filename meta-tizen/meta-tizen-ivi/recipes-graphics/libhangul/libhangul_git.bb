require libhangul.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/uifw/libhangul;tag=2fe339978867090f76ae0ebb1b1863e374b63ee2;nobranch=1"

BBCLASSEXTEND += " native "

