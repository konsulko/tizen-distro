require ecryptfs-utils.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/ecryptfs-utils;tag=f496d10d2711cbb2b9d3f7600756487df383e737;nobranch=1"

BBCLASSEXTEND += " native "

