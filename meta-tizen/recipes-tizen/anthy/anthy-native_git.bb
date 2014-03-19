require anthy.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/uifw/anthy;protocol=ssh;tag=5e7a08ab59c9c1f97eb4fa7e05c4c8dd30ed1753;nobranch=1"

