require oma-ds-agent.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/oma-ds-agent;protocol=ssh;tag=47e30b8e569328719424b1af9cd6c26b34f9d572;nobranch=1"

