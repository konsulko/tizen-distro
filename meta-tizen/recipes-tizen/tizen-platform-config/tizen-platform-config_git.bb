require tizen-platform-config.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/tizen-platform-config;tag=12f2548e81994d97efc7f62bb8eb10ac4079e273;nobranch=1"

BBCLASSEXTEND += " native "

