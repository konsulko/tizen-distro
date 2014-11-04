require common-multimedia-suite.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/test/common/common-multimedia-suite;tag=0a75992bd0357284a47973ebba5264bc2f18e8b6;nobranch=1"

BBCLASSEXTEND += " native "

