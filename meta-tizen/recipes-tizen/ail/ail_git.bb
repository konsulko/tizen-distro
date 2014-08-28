require ail.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/ail;tag=d8b4d50672dce40fce54cf1c43a6e4a7a064c982;nobranch=1"

BBCLASSEXTEND += " native "

