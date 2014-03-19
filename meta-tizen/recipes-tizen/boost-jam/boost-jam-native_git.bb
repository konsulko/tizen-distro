require boost-jam.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/boost-jam;protocol=ssh;tag=2e801cdf3a5993b849d0ab42e96a01040bf0897c;nobranch=1"

