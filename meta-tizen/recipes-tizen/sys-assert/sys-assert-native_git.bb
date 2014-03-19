require sys-assert.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/sys-assert;protocol=ssh;tag=ee0439aa62b8e860535bab68af71f461eb8dd1fa;nobranch=1"

