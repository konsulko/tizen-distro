require fixesproto.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/fixesproto;protocol=ssh;tag=f5b3e23ce67b02f6bdcaba8c94fb947df3b44d27;nobranch=1"

