require lemolo.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/lemolo;tag=891067cc10ac3c107145ea5af418b1b4888af203;nobranch=1"

BBCLASSEXTEND += " native "

