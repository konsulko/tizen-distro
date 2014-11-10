require download-provider.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/framework/web/download-provider;tag=1fb4a3614bd271355b6babf42076d3bda2da122c;nobranch=1"

BBCLASSEXTEND += " native "

