require python-lxml.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/python-lxml;protocol=ssh;tag=89b6fc6a4d352ebfe61e1873dabe71406a0490e1;nobranch=1"

