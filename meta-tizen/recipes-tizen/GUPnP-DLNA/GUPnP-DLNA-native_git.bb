require GUPnP-DLNA.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/profile/ivi/GUPnP-DLNA;protocol=ssh;tag=243e8bfef2256c944c0202e62c1612ee5e341f30;nobranch=1"

