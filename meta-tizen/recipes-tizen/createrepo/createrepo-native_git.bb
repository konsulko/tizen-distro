require createrepo.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/createrepo;protocol=ssh;tag=3bba8eb0a7b7a11090fa8aa469c3609ff8e29089;nobranch=1"

