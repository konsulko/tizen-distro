require libhangul.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/uifw/libhangul;tag=baabd61475fc93629b69dc03de4ffe3a1a42f460;nobranch=1"

BBCLASSEXTEND += " native "

