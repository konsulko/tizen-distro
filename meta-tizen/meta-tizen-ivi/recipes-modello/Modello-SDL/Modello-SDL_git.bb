require Modello-SDL.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_SDL;tag=c6bb5a39bf009bbca2cbb6e1559a04529b9f4617;nobranch=1"

BBCLASSEXTEND += " native "

