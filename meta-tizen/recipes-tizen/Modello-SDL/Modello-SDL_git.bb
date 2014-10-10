require Modello-SDL.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_SDL;tag=d03890cc6ce2dca421e1bb8c4746ee5269c0c2dd;nobranch=1"

BBCLASSEXTEND += " native "

