require vpnc.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/vpnc;protocol=ssh;tag=d12c99e3b5070aa1af805c49f5e514f99c459f79;nobranch=1"

