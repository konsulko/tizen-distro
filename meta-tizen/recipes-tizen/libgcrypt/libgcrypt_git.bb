require libgcrypt.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libgcrypt;protocol=ssh;tag=0a783dc5999fbf8ded0da5e16b4c39ce88dfc978;nobranch=1"

