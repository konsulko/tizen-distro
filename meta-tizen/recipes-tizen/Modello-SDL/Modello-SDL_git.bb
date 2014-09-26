require Modello-SDL.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_SDL;tag=8c233b3ab7d8d27fa20777594ba05b6ff433ebcd;nobranch=1"

BBCLASSEXTEND += " native "

