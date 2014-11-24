require rpm.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/rpm;tag=beaf75391c4da89c2c7d399b4027a1c5a91f5f86;nobranch=1"

BBCLASSEXTEND += " native "

