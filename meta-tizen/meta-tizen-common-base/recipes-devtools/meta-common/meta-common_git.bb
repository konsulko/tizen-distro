require meta-common.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/common/meta;tag=e0b55742c3a4d35d44168a2eb1fb1367c1f37481;nobranch=1"

BBCLASSEXTEND += " native "

