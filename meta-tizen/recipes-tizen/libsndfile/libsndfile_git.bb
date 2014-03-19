require libsndfile.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libsndfile;protocol=ssh;tag=3cd0e33c3144bea326a8cd6f17b44ed5ab037a17;nobranch=1"

