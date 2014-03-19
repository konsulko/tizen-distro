require lzop.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/lzop;protocol=ssh;tag=5b56bd67c8ad4362c62c08cbe09d76f8db558638;nobranch=1"

