require wrt-security.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/framework/web/wrt-security;protocol=ssh;tag=57fe991c1330a5e41c901a3497bbaa6ec0863f49;nobranch=1"

