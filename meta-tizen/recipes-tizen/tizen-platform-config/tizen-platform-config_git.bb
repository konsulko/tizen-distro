require tizen-platform-config.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/tizen-platform-config;tag=4decfd92f8a259976d8322388c929f70146b3230;nobranch=1"

BBCLASSEXTEND += " native "

