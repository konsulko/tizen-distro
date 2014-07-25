require efl.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/efl;tag=44c41170575d811cc18c8ea57de593f7f4c46129;nobranch=1"

BBCLASSEXTEND += " native "

