require lemolo.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/lemolo;tag=011e1d7ab747693bfddf72e566ef71d483e71492;nobranch=1"

BBCLASSEXTEND += " native "

