require application.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/application;tag=c92cec0e876d638b91eb64e12e306e9a29ed2e8f;nobranch=1"

BBCLASSEXTEND += " native "

