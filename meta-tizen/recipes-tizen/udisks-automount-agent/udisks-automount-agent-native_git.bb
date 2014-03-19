require udisks-automount-agent.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/apps/core/preloaded/udisks-automount-agent;protocol=ssh;tag=949c48c0d17849664c338bdd33759f33649c97dc;nobranch=1"

