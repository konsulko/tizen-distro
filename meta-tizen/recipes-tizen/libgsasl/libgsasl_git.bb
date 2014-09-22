require libgsasl.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libgsasl;tag=edbe0cde3ef2bf4bc1248f053ddcf210fb27f2b3;nobranch=1"

BBCLASSEXTEND += " native "

