require gsignond.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gsignond;tag=572cf9261e1233c5db1b74b74a70d97289d752a2;nobranch=1"

BBCLASSEXTEND += " native "

