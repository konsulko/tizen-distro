require murphy.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/murphy;tag=23cf28af5042e100997008c53e05a3cfe6e3a7b1;nobranch=1"

BBCLASSEXTEND += " native "

