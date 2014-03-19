require geocoder.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/geocoder;protocol=ssh;tag=f3ab5ec7eb99416b34710c421ff60dd6bc90f89f;nobranch=1"

