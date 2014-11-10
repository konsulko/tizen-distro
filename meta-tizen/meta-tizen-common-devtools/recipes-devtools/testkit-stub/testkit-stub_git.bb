require testkit-stub.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/test/tools/testkit-stub;tag=47df47cf49ed04b7c37c011a0aa582e3d147563b;nobranch=1"

BBCLASSEXTEND += " native "

