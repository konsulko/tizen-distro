require testkit-lite.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/test/tools/testkit-lite;protocol=ssh;tag=70515a2d60bdb13fc2051006c3393b7ee94154e5;nobranch=1"

