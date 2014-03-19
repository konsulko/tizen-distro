require perl-XML-Simple.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/perl-XML-Simple;protocol=ssh;tag=763f57225253ab5978fbd470f9196d1ea8efbfcc;nobranch=1"

