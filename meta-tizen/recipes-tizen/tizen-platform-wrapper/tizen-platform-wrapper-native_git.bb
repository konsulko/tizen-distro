require tizen-platform-wrapper.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/tizen-platform-wrapper;protocol=ssh;tag=ddda0a79a93d4fae22b39467b0d095267f5ea66b;nobranch=1"

