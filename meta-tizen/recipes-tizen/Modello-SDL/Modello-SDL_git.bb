require Modello-SDL.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_SDL;tag=ca736df169a33e30e7bdb2a7b37307a67d3d7ba7;nobranch=1"

BBCLASSEXTEND += " native "

