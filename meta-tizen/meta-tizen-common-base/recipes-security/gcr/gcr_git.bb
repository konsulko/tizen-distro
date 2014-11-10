require gcr.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gcr;tag=3d139a70d06ebf222b786a00cd6d3af2f473f4d7;nobranch=1"

BBCLASSEXTEND += " native "

