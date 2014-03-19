require GUPnP-AV.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/GUPnP-AV;protocol=ssh;tag=ac5d118a0b108c65de8deba1a6d8969df7f64434;nobranch=1"

