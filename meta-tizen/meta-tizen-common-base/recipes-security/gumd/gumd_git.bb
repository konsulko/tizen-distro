require gumd.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gumd;tag=f247444ac80494744acf7e5678482398f4f0adee;nobranch=1"

BBCLASSEXTEND += " native "

