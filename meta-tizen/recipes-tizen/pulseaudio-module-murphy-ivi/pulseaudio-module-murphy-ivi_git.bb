require pulseaudio-module-murphy-ivi.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/pulseaudio-module-murphy-ivi;tag=b81902a13e47d93f066bb130c928d831cfe53beb;nobranch=1"

BBCLASSEXTEND += " native "

