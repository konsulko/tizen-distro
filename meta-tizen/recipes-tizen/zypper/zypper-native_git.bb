require zypper.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/zypper;protocol=ssh;tag=f1d4cfc301168fe4d1f9a804a6450eac8f196e62;nobranch=1"

