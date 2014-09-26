require Modello-Nav.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/Modello_Nav;tag=4e79aa3f0cf8381ab3157a9145c12b0385651140;nobranch=1"

BBCLASSEXTEND += " native "

