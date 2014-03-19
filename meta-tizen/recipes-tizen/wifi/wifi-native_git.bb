require wifi.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/wifi;protocol=ssh;tag=391e3b9f55f1dc7339c6aba23738c6bdf116eb77;nobranch=1"

