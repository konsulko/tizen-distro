require sessreg.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/sessreg;protocol=ssh;tag=59d6be87da03db7979f316eb886e95d68dbd2eaa;nobranch=1"

