require url-download.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/url-download;protocol=ssh;tag=aad34a2c7481017a876cdd790e216ef1bc6409e4;nobranch=1"

