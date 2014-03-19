require docbook-4.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/docbook_4;protocol=ssh;tag=e6a71527bb63fd14a915e11c0a2575e7c23e38c9;nobranch=1"

