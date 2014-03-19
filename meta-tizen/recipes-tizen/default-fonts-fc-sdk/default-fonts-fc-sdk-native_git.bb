require default-fonts-fc-sdk.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/graphics/default-fonts-fc-sdk;protocol=ssh;tag=1d1be0df95b1ff677eb95d87100ccd75023fbb91;nobranch=1"

