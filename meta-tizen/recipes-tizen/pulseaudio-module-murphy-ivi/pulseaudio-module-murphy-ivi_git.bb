require pulseaudio-module-murphy-ivi.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/pulseaudio-module-murphy-ivi;tag=1d515e19a11c4eb61324141e026ced7bf02ce89a;nobranch=1"

BBCLASSEXTEND += " native "

