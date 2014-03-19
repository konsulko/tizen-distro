require tizen-branding-default.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/tizen-branding-default;protocol=ssh;tag=a18b947db2fd63f301f9fa9c0db6102154a5ffe9;nobranch=1"

