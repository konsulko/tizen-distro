require common-sanity-suite.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/test/common/common-sanity-suite;tag=6f3bf9868483eeab094d4230be0dd1aa2c9f90f4;nobranch=1"

BBCLASSEXTEND += " native "

