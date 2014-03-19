require eio.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/eio;protocol=ssh;tag=67183878bee3c704aa899bd71b4ed5f0ba1f77a4;nobranch=1"

