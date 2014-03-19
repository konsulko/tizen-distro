require usb-manager.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/apps/core/preloaded/usb-manager;protocol=ssh;tag=94b0c5456eccadd3d7cdf23e4185b7cbbfd2e809;nobranch=1"

