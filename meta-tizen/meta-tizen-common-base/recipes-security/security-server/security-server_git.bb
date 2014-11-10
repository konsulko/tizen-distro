require security-server.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/security/security-server;tag=ae009054afbe5b8885da76af1a8127daa63742f6;nobranch=1"

BBCLASSEXTEND += " native "

