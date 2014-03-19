require libcamsrcjpegenc.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/multimedia/libcamsrcjpegenc;protocol=ssh;tag=8978d60f7056ec5b45a89814346c54b576dcc52c;nobranch=1"

