require mic.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/mic;protocol=ssh;tag=6a69ef958deb5042a1988ba06b96a1cf23fc0fc8;nobranch=1"

