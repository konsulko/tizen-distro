require dbus-python.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/dbus-python;tag=0910bc53d2965584e7305b4f32158fa56af6197f;nobranch=1"

BBCLASSEXTEND += " native "

