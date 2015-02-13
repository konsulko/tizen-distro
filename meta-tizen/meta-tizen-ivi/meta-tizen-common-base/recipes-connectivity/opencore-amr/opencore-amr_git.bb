require opencore-amr.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/opencore-amr;tag=72a792824e352ad4084c3729154a444f57b7b8bb;nobranch=1"

BBCLASSEXTEND += " native "

