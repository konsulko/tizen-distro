require pulseaudio-module-murphy-ivi.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/pulseaudio-module-murphy-ivi;tag=eacc58c41e0ba000c2faa14e60c72ebf02fe258d;nobranch=1"

BBCLASSEXTEND += " native "

