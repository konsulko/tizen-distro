require capi-content-media-content.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/media-content;tag=f8e097736df02e1686da42f2d56ea31ad4a7bac2;nobranch=1"

BBCLASSEXTEND += " native "

