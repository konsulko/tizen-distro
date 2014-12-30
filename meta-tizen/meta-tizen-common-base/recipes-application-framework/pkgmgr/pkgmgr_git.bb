require pkgmgr.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/slp-pkgmgr;tag=8e066407e4c75d9c79a0c797b884f7fab22ec6c3;nobranch=1"

BBCLASSEXTEND += " native "

