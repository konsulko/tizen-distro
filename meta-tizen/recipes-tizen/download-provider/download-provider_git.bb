require download-provider.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/framework/web/download-provider;tag=6ad4737fe27b987c48391debc24b3678fd002a38;nobranch=1"

BBCLASSEXTEND += " native "

