require python-requests.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/python-requests;tag=10e958cb8d3786946e30d4114f8afe27b9daccaf;nobranch=1"

BBCLASSEXTEND += " native "

