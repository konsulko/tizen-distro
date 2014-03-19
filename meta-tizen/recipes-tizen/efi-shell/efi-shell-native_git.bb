require efi-shell.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/efi-shell;protocol=ssh;tag=53b6e6a59db79b6978508f69c6e9712449f38abf;nobranch=1"

