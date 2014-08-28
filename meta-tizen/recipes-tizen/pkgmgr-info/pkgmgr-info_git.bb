require pkgmgr-info.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/pkgmgr-info;tag=924179f7a9b9e8b9145faca1ff54fb545836b784;nobranch=1"

BBCLASSEXTEND += " native "

