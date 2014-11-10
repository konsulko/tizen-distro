require secure-storage.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/security/secure-storage;tag=8e5c4dc0f1b514a945d0972d701a618e462f7adf;nobranch=1"

BBCLASSEXTEND += " native "

