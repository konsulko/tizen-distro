require gsignond.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gsignond;tag=7205ca5442c3c3f48bbccf2b707df15a3e3da32a;nobranch=1"

BBCLASSEXTEND += " native "

