require krb5.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/krb5;protocol=ssh;tag=a98efd0c8f97aba9d71c2130c048f1adc242772e;nobranch=1"

