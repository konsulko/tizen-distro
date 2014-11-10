require elementary.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/elementary;tag=48de6fe3127b0e8da306d0fa0b181469b101e3af;nobranch=1"

BBCLASSEXTEND += " native "

