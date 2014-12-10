require common-crosswalk-suite.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/test/common/common-crosswalk-suite;tag=61b29331a9e9dd4798611d401f2517b9f5c93292;nobranch=1"

BBCLASSEXTEND += " native "

