require Modello-SDL.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_SDL;tag=2c883eb27a32bee3cc6459a3bb93f2ed5ba8ead6;nobranch=1"

BBCLASSEXTEND += " native "

