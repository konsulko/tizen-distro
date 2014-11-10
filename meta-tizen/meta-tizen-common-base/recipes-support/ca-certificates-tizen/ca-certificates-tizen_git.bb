require ca-certificates-tizen.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/security/ca-certificates-tizen;tag=7bb7ed313e91c42a57f2abf3560ce4db5baa9a4b;nobranch=1"

BBCLASSEXTEND += " native "

