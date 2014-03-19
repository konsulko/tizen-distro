require xmlstarlet.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/xmlstarlet;protocol=ssh;tag=0318a18f88969374cf920c7b9a042b42819db76a;nobranch=1"

