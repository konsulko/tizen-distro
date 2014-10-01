require Modello-SDL.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_SDL;tag=17ec89ac37010ab281e9e2a0147b8aa5b5d1d0b3;nobranch=1"

BBCLASSEXTEND += " native "

