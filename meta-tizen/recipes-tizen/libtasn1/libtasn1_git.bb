require libtasn1.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libtasn1;protocol=ssh;tag=49a3ae6bbf329c1ba35cd65522fb8236bdf3d3f4;nobranch=1"

