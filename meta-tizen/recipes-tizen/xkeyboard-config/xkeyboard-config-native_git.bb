require xkeyboard-config.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/xkeyboard-config;protocol=ssh;tag=34072ac15efdf2a8cb82b77c00a0b673465b568b;nobranch=1"

