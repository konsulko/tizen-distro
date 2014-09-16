require sphinxbase.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/sphinxbase;tag=0404a5e1800547ab86ee18bd41414877f4596fa2;nobranch=1"

BBCLASSEXTEND += " native "

