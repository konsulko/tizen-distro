require qtxmlpatterns.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/qtxmlpatterns;protocol=ssh;tag=1f0f14a897a4d0ec95f9c42202ac3e0005ce2ddc;nobranch=1"

