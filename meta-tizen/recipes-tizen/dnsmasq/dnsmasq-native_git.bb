require dnsmasq.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/dnsmasq;protocol=ssh;tag=881972c6f6dbe50dcfd039e27e22a993a6bc7106;nobranch=1"

