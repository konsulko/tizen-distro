require libslp-memo.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/apps/core/preloaded/libslp-memo;tag=442e794292a7868f493f20d80438f13ff0e1db26;nobranch=1"

BBCLASSEXTEND += " native "

