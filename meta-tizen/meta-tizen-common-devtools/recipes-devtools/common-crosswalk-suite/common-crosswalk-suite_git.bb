require common-crosswalk-suite.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/test/common/common-crosswalk-suite;tag=43f12d43db99ba46319f3c245e9aeb9d3fac82f0;nobranch=1"

BBCLASSEXTEND += " native "

