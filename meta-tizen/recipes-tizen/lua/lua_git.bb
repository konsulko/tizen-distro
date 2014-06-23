require lua.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/lua;tag=ccbaf72a5d0d0f8ab6a1bf64e851a00026f28fd8;nobranch=1"

BBCLASSEXTEND += " native "

