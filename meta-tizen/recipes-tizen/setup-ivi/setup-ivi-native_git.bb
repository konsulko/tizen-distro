require setup-ivi.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/setup-ivi;protocol=ssh;tag=3f74c7f66be172b3e05666d3cec52b945f3a9ac5;nobranch=1"

