require python-gobject.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/python-gobject;protocol=ssh;tag=b52bdecc1599e6a557456711b068eba907890758;nobranch=1"

