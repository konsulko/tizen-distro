require ecryptfs-utils.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/ecryptfs-utils;tag=08e0a8386a45bb99eca999f934eb4d9ae0110f7e;nobranch=1"

BBCLASSEXTEND += " native "

