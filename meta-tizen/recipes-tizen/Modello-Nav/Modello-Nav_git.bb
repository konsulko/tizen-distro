require Modello-Nav.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Nav;tag=d76a933011dc0c1af9a89a8b0fceba2924ee7840;nobranch=1"

BBCLASSEXTEND += " native "

