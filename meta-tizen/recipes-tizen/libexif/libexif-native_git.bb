require libexif.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libexif;protocol=ssh;tag=c648945fce720d35b6fd35f7ac0db4cbe6dd9e55;nobranch=1"

