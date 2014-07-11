require libslp-pm.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/libslp-pm;tag=2ee02d3b0050b1a0d37fc0d2d3990d9823916c61;nobranch=1"

BBCLASSEXTEND += " native "

