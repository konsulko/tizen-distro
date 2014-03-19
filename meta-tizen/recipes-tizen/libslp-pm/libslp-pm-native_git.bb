require libslp-pm.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/system/libslp-pm;protocol=ssh;tag=b3344528f667ed4b7a53034597e9ac550a1dcad3;nobranch=1"

