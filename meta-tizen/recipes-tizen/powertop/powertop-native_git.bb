require powertop.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/powertop;protocol=ssh;tag=f6b0d9de6a1b323ccd287e28fd1bcaf886719ab7;nobranch=1"

