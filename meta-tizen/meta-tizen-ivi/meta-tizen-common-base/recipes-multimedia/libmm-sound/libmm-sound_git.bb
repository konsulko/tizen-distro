require libmm-sound.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmm-sound;tag=c7f783deb5d7b5629cec0f155e0954672c8f31ef;nobranch=1"

BBCLASSEXTEND += " native "

