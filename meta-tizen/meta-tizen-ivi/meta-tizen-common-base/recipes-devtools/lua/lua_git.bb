require lua.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/lua;tag=25c38c5d6cf919f6e0c37413955c20dbea24d37f;nobranch=1"

BBCLASSEXTEND += " native "

