require sphinxbase.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/sphinxbase;tag=dfd0999be40186cbf473dc9d41b6196df06861a8;nobranch=1"

BBCLASSEXTEND += " native "

