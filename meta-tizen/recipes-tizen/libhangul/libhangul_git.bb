require libhangul.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/uifw/libhangul;tag=1f08e8e287b8409e363fe9588fd52de9530a506c;nobranch=1"

BBCLASSEXTEND += " native "

