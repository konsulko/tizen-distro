require cert-svc.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/security/cert-svc;protocol=ssh;tag=91e2d40d5548afdf8a76889a9497d41784d3e926;nobranch=1"

