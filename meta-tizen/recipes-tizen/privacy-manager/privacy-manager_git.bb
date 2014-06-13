require privacy-manager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/security/privacy-manager;tag=3ca7a656bf292b9692dbe73e58db7c2f6a931c6e;nobranch=1"

BBCLASSEXTEND += " native "

