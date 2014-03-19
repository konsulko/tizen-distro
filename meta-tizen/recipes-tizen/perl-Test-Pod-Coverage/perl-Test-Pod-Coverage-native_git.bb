require perl-Test-Pod-Coverage.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/perl-Test-Pod-Coverage;protocol=ssh;tag=1bdf99094c7998ab7fa63502367e163412735bf0;nobranch=1"

