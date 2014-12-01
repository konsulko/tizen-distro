require meta-generic.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/meta-generic;tag=146ff92e0e7bfecd4bbeefea6c49a2c82c1feab4;nobranch=1"

BBCLASSEXTEND += " native "

