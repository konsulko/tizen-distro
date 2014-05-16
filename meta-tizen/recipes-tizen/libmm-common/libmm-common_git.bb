require libmm-common.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmm-common;tag=d7abefd924b8cbe245425b70a0c0911ec5e73115;nobranch=1"

BBCLASSEXTEND += " native "

