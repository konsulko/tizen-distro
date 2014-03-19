require sys-string-0.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/base/sys-string-0;protocol=ssh;tag=675d98bc92856f574b5090ce4c714e0a03f32af3;nobranch=1"

