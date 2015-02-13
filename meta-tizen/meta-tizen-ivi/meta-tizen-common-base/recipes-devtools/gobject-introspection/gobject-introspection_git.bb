require gobject-introspection.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gobject-introspection;tag=6c15fe2f7415421fd1d38d03d8865c0e3e4c9967;nobranch=1"

BBCLASSEXTEND += " native "

