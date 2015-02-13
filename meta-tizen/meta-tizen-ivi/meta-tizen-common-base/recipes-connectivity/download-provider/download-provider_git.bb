require download-provider.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/framework/web/download-provider;tag=cfad1aa260356701996248ded3e9c90541ddcb11;nobranch=1"

BBCLASSEXTEND += " native "

