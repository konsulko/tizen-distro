require weston.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/weston;tag=1884117b59372e9b9fb80a820ece08302aea1eab;nobranch=1"

BBCLASSEXTEND += " native "

