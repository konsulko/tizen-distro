require libmm-player.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmm-player;tag=7a97ce895b719ae4cf99bb0d6ca1715c1f4c265b;nobranch=1"

BBCLASSEXTEND += " native "

