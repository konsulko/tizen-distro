require Modello-Phone.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Phone;tag=7713f7d4798edb44f29a1d3ed4675b35a11b3a7d;nobranch=1"

BBCLASSEXTEND += " native "

