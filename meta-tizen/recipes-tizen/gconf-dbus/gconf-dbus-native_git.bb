require gconf-dbus.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/base/gconf-dbus;protocol=ssh;tag=434a129379da8e8afb892cf5498466cf34ff9d18;nobranch=1"

