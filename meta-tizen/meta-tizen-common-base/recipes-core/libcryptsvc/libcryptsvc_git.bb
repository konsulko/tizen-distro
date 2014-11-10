require libcryptsvc.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/security/libcryptsvc;tag=a59f1b1f2853ba347705bbdd97f587ebe946bb80;nobranch=1"

BBCLASSEXTEND += " native "

