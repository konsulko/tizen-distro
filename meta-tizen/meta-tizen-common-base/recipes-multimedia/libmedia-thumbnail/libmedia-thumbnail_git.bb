require libmedia-thumbnail.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libmedia-thumbnail;tag=b97d0b8ec596a5e17dbec92fd4e487ec9a91f8ef;nobranch=1"

BBCLASSEXTEND += " native "

