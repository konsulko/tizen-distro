require syspopup.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/base/syspopup;protocol=ssh;tag=df872617708a23dd665e3718e28b1d2690605489;nobranch=1"

