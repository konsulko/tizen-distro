require com-core.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/com-core;protocol=ssh;tag=ceffb3798e829b8f2a22efd7b0c97a7848a7b24d;nobranch=1"

