require dbus-glib.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/dbus-glib;protocol=ssh;tag=a2ab54dba6cdd32666c642b3a5d58e14ae150a01;nobranch=1"

