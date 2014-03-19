require perl-XML-Parser.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/perl-XML-Parser;protocol=ssh;tag=a466ad372216f129768e25c4ef999c51a834f0cf;nobranch=1"

