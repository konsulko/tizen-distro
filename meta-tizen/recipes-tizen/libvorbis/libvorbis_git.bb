require libvorbis.inc

PRIORITY = "10"

LIC_FILES_CHKSUM ??= "file://${COMMON_LICENSE_DIR}/GPL-2.0;md5=801f80980d171dd6425610833a22dbe6"

SRC_URI += "git://review.tizen.org/platform/upstream/libvorbis;protocol=ssh;tag=e4c8e81efeb8b39d14f88cece4ab1396e7350594;nobranch=1"

