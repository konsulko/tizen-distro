require libaccounts-svc.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/pim/libaccounts-svc;protocol=ssh;tag=61b98be83d118af2bcfc25c6e16f2e7dbcf77720;nobranch=1"

