require gnutls.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/gnutls;protocol=ssh;tag=b3c129db29e4b4d6bdeb6980872a5c4a14a24ae8;nobranch=1"

