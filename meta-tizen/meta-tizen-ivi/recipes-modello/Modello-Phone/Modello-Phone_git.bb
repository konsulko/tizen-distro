require Modello-Phone.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Phone;tag=6c3f53db4d0f26795d5f80ea7405a5f2caef3754;nobranch=1"

BBCLASSEXTEND += " native "

