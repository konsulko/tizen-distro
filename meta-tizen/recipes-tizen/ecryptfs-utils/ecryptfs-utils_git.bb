require ecryptfs-utils.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/ecryptfs-utils;tag=0342ba1b12a89cc2d2a9d9b820c8270585bee62c;nobranch=1"

BBCLASSEXTEND += " native "

