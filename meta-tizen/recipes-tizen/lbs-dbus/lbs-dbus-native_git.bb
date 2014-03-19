require lbs-dbus.inc

PRIORITY = "9"

inherit native

S = "${WORKDIR}/git"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/core/location/lbs-dbus;protocol=ssh;tag=219010f23de1dcc5e57c9c314a241d8ab8840fd0;nobranch=1"

