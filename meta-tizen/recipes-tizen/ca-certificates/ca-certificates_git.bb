require ca-certificates.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/ca-certificates;protocol=ssh;tag=61ba96834fcd87931cc453f9dcc6f9184602c8a5;nobranch=1"

