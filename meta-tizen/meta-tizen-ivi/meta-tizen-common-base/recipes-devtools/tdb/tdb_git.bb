require tdb.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/tdb;tag=915e4e6232f6c4ba962656dc632615e2d4909480;nobranch=1"

BBCLASSEXTEND += " native "

