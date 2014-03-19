require app-manager.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/app-manager;protocol=ssh;tag=13054cca243234d5617b0ecb489487ab2bf9d46c;nobranch=1"

