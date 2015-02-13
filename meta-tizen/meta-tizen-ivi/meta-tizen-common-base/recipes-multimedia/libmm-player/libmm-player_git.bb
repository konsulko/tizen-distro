require libmm-player.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmm-player;tag=d396a30a561a0db96094560b21e24e99029481c0;nobranch=1"

BBCLASSEXTEND += " native "

