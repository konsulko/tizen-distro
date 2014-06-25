require media-content.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/media-content;tag=24ac293591b551f132d5bc113a48a189ce024024;nobranch=1"

BBCLASSEXTEND += " native "

