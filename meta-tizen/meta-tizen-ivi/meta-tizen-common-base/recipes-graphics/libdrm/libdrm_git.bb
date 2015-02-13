require libdrm.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libdrm;tag=2a8aaf2b9f403cde35b88653394906af578845ab;nobranch=1"

BBCLASSEXTEND += " native "

