require libwbxml2.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libwbxml2;tag=e7ff0d80b8638cd60e06be6d8a3c9364b617ffb1;nobranch=1"

BBCLASSEXTEND += " native "

