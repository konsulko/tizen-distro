require perl-WWW-Curl.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/perl-WWW-Curl;protocol=ssh;tag=3d7755f418633e4b2eda8c8a4b1ae156ec1b65ed;nobranch=1"

