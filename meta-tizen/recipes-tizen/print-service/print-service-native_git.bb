require print-service.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/apps/core/preloaded/print-service;protocol=ssh;tag=d552bd8c550393e9db38b1bd9903972a205e9aaa;nobranch=1"

