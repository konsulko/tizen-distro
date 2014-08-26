require download-provider.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/framework/web/download-provider;tag=0bf02f3d4683689e0bdb132e0ff1ccee1e328ad9;nobranch=1"

BBCLASSEXTEND += " native "

