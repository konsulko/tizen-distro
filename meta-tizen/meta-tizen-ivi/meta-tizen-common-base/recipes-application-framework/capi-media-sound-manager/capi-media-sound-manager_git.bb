require capi-media-sound-manager.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/sound-manager;tag=4232dc89238c674ae1fcc240cb19547e2a92bae0;nobranch=1"

BBCLASSEXTEND += " native "

