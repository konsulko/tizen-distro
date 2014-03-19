require usb-accessory.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/usb-accessory;protocol=ssh;tag=781124b331d2c76b107fbfd5fb34d2cce882da74;nobranch=1"

