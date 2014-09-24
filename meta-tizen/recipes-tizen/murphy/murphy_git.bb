require murphy.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/murphy;tag=f41ce196884f7b83e805d5f52e84b1ab831bab73;nobranch=1"

BBCLASSEXTEND += " native "

