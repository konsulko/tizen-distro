require testkit-lite.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/test/tools/testkit-lite;tag=da799487c06614bf07afd6006f2a57520f3f036c;nobranch=1"

BBCLASSEXTEND += " native "

