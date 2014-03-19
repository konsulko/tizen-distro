require xf86miscproto.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/xf86miscproto;protocol=ssh;tag=7c953229b786512054956bd6e93796fd2ca1d527;nobranch=1"

