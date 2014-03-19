require libarchive.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libarchive;protocol=ssh;tag=ba2e8d039bc53e80ac9ea8ee6415b8277c9e3796;nobranch=1"

