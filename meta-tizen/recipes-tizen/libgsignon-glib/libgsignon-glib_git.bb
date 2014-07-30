require libgsignon-glib.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libgsignon-glib;tag=67eb010626e2c146340925219d0ac47a53d50f3f;nobranch=1"

BBCLASSEXTEND += " native "

