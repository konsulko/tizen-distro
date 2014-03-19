require swig.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/swig;protocol=ssh;tag=9bfcbd7df73d296e6622f92191448b5ec0d1df7f;nobranch=1"

