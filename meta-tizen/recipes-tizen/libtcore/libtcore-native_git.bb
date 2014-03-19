require libtcore.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/telephony/libtcore;protocol=ssh;tag=dfe76ded0c37f2cbe91b173c94b7f573ebec3df9;nobranch=1"

