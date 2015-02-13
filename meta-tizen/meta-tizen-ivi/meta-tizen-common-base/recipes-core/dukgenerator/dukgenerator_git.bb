require dukgenerator.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/security/dukgenerator;tag=dba9f75b65f93b0139eb79e634252ce7a7c8d06d;nobranch=1"

BBCLASSEXTEND += " native "

