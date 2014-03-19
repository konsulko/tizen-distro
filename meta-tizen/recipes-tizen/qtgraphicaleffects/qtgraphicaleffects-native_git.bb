require qtgraphicaleffects.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/qtgraphicaleffects;protocol=ssh;tag=82146cad070b04379c930e72573f983a75372621;nobranch=1"

