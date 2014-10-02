require audio-session-manager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/audio-session-manager;tag=e3971547dc8877cb20ab39f5e437f5dc40a275a0;nobranch=1"

BBCLASSEXTEND += " native "

