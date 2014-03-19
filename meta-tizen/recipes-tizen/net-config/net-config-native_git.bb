require net-config.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/connectivity/net-config;protocol=ssh;tag=a35c5e1be2c01ae6d00dc2fb42a13bb72569edd6;nobranch=1"

