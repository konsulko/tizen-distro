require weston.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/weston;tag=e54320a932898e57be56b7e2ecdfde45f9f234ce;nobranch=1"

BBCLASSEXTEND += " native "

