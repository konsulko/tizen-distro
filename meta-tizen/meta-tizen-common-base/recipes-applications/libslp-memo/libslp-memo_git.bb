require libslp-memo.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/apps/core/preloaded/libslp-memo;tag=2d7a05e35636d8a379f4f2eaac3b180c51e18592;nobranch=1"

BBCLASSEXTEND += " native "

