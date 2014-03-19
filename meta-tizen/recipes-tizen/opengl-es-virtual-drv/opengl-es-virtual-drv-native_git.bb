require opengl-es-virtual-drv.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/opengl-es-virtual-drv;protocol=ssh;tag=9bac49a769fe5e048df214e463c01da2de757516;nobranch=1"

