require pulseaudio.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/pulseaudio;tag=6a1a844dbcb898d381105cd3a5b4c3a32effef3f;nobranch=1"

BBCLASSEXTEND += " native "

