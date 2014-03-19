require build-compare.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/build-compare;protocol=ssh;tag=b9f09e982b7730b0ecdfc7f3fdac477175eee5bb;nobranch=1"

