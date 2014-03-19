require iso-codes.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/iso-codes;protocol=ssh;tag=441ef980d82e26b1e859b2b1823b63697916cede;nobranch=1"

