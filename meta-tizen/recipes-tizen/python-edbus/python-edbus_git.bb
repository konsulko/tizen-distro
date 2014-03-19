require python-edbus.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/python-edbus;protocol=ssh;tag=002d893c0cc3979da173eccc6de8d3a16f8c7058;nobranch=1"

