require libgsignon-glib.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libgsignon-glib;tag=4c38ceaa060430023737564f510fb307f2515cf0;nobranch=1"

BBCLASSEXTEND += " native "

