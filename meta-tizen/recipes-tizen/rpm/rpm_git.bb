require rpm.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/rpm;tag=d81d7b2f5c69ec104400b5d8fcfbcbc88d3bfd63;nobranch=1"

BBCLASSEXTEND += " native "

