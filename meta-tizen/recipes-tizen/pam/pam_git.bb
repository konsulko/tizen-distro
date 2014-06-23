require pam.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/pam;tag=00107b54a1f8f846b0defd1a00b04e5f72990959;nobranch=1"

BBCLASSEXTEND += " native "

