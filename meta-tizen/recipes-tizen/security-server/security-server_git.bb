require security-server.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/security/security-server;tag=a708c47a514f5a890737b1e70fc470687e1d23a4;nobranch=1"

BBCLASSEXTEND += " native "

