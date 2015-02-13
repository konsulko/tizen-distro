require capi-media-image-util.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/image-util;tag=8d92beab51da8bbdca0099de4ed5dbc95f64555c;nobranch=1"

BBCLASSEXTEND += " native "

