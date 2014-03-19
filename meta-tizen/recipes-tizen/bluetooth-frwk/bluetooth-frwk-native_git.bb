require bluetooth-frwk.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/connectivity/bluetooth-frwk;protocol=ssh;tag=f239d393cfb97a214d3fb0131ada9f523d12e6b8;nobranch=1"

