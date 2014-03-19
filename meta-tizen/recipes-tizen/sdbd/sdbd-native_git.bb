require sdbd.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/sdk/target/sdbd;protocol=ssh;tag=b4d305e5e1cefa42d3300f7601493bce58f9c107;nobranch=1"

