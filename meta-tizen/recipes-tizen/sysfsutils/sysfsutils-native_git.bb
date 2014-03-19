require sysfsutils.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/sysfsutils;protocol=ssh;tag=e9dfe180eb604903471f538bc4d15e8423754c3a;nobranch=1"

