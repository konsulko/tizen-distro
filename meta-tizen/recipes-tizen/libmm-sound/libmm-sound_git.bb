require libmm-sound.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmm-sound;tag=4192934b34ade9d554a37df5a8fe46ebcee4befd;nobranch=1"

BBCLASSEXTEND += " native "

