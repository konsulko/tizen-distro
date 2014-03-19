require favorites.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/api/favorites;protocol=ssh;tag=b7d3b209e89a68b973cb03f8bf1ea4bc06fff99e;nobranch=1"

