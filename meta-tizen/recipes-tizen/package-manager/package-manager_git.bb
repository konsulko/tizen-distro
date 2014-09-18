require package-manager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/package-manager;tag=f3bb3a3ca795f4c38fbf51a3c6696d342b0cf0eb;nobranch=1"

BBCLASSEXTEND += " native "

