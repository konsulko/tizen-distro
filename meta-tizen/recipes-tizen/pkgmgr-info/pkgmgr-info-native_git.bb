require pkgmgr-info.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/pkgmgr-info;protocol=ssh;tag=ea4b6878402b97e87f004eaae074e9b6571da8df;nobranch=1"

