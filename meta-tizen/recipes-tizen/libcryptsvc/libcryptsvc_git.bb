require libcryptsvc.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/security/libcryptsvc;protocol=ssh;tag=1266a27e7741b4325b9b16c33508073fedd6a052;nobranch=1"

