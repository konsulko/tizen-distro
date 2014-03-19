require sgml-skel.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/sgml-skel;protocol=ssh;tag=a3c551b81491f43c7e3540f3d3a893ffcf3a0cce;nobranch=1"

