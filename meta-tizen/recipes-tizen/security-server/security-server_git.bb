require security-server.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/security/security-server;tag=2ed4c64c78df05eb8f1f4ba200dafb638cc5307c;nobranch=1"

BBCLASSEXTEND += " native "

