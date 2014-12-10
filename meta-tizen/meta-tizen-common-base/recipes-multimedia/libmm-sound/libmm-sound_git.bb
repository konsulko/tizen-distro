require libmm-sound.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmm-sound;tag=1cd4ad61333ee2b961e0def7a57bfaa266d4bcbc;nobranch=1"

BBCLASSEXTEND += " native "

