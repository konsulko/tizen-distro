require patchelf.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/patchelf;protocol=ssh;tag=34472e50842c1462eb063abff391ae9c7abbdcba;nobranch=1"

