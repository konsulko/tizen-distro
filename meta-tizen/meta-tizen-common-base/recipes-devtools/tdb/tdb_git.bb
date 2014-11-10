require tdb.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/tdb;tag=b256247b2afa3bfe52664f58d95974eea9d236d7;nobranch=1"

BBCLASSEXTEND += " native "

