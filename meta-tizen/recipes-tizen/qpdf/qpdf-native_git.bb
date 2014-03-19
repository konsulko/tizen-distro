require qpdf.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/qpdf;protocol=ssh;tag=0561f388f298abbf6d6cebe3aafbb71f22b2d61e;nobranch=1"

