require bundle.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/base/bundle;tag=e36cdeba173a93b72110b536094220e1a00c566c;nobranch=1"

BBCLASSEXTEND += " native "

