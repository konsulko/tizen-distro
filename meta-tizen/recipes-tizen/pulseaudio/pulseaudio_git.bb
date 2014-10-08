require pulseaudio.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/pulseaudio;tag=c91f47e3d11e72bf583f7d84643a9d768c168684;nobranch=1"

BBCLASSEXTEND += " native "

