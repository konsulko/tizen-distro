require common-graphics-suite.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/test/common/common-graphics-suite;tag=2ed6a477adc8d08c3efabaf8034bd16d4eabe779;nobranch=1"

BBCLASSEXTEND += " native "

