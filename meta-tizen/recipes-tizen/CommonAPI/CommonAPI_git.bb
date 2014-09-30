require CommonAPI.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/common-api-runtime;tag=307112a91ac86e5a4fb3cc0b7c772a561e6845d3;nobranch=1"

BBCLASSEXTEND += " native "

