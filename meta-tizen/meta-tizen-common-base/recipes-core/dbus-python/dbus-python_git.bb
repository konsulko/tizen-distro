require dbus-python.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/dbus-python;tag=d3f0ade3c2e6d096fc84bd676cd87f2726a3108e;nobranch=1"

BBCLASSEXTEND += " native "

