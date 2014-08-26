require net-config.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/connectivity/net-config;tag=cec997fc07d2c83bb6b50478c0fc69a881999e08;nobranch=1"

BBCLASSEXTEND += " native "

