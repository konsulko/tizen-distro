require gpgme.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gpgme;protocol=ssh;tag=020813a39ceb976ef3bb0c4ba4ae5c8c1fbd268e;nobranch=1"

