require pulseaudio.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/pulseaudio;tag=9f3f3d9dfe4449a019945f65002f714aa49dcc2d;nobranch=1"

BBCLASSEXTEND += " native "

