require rpm.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/rpm;tag=b56ed49a97939d11dd4270c9550966c43b9ce5a6;nobranch=1"

BBCLASSEXTEND += " native "

