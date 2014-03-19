require vconf.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/appfw/vconf;protocol=ssh;tag=5cdc2874cdc9b3cdcdb2289330403f192fcdfae0;nobranch=1"

