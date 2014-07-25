require security-server.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/security/security-server;tag=d369e5c89a3652d961d3986d4a4136fb647e2b8c;nobranch=1"

BBCLASSEXTEND += " native "

