require dbus-python.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/dbus-python;tag=a8f0e5c73d4bbf6068a598971ad24135a881fab9;nobranch=1"

BBCLASSEXTEND += " native "

