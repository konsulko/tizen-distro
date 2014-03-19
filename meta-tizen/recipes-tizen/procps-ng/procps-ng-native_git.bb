require procps-ng.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/procps-ng;protocol=ssh;tag=615af17453a0e5db4cab45b46fdcc50d5f6c2f5c;nobranch=1"

