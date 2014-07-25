require tizen-platform-wrapper.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/tizen-platform-wrapper;tag=b2855ffc77dcb11586c82d037f6defdaa5aaf800;nobranch=1"

BBCLASSEXTEND += " native "

